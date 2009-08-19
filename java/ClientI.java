import NWN.*;
import java.util.*;

class ClientI extends Observable implements _ClientOperations {
	private Map<Long, Anon> tokens =
		Collections.synchronizedMap(new HashMap<Long,Anon>());
	private Set<Anon> delayedThunks =
		Collections.synchronizedSet(new HashSet<Anon>());

	private volatile long lastToken = 0;
	private volatile NWObject self;
	private volatile NWScriptPrx proxy;
	private final NWObject module = new NWObject(0);

	public synchronized void schedule(Anon code) {
		delayedThunks.add(code);
	}

	public NWScriptPrx getProxy() {
		return proxy;
	}
	public NWObject getObjectSelf() {
		return self;
	}

	public void assign(NWObject obj, Anon code, Double delay) throws NotInContextException {
		if (obj.equals(this.self) && delay == 0.0) {
			// This saves us a round trip, because NWScripts OBJECT_SELF is
			// already properly set.
			code.e();

		} else {
			Long token = lastToken++;
			tokens.put(token, code);

			proxy.setLocalString(module, "ice_token", token.toString());
			proxy.setLocalFloat(module, "ice_token_delay", delay);
			proxy.executeScript("ice_token", obj);
		}
	}

	// The 'action' variable type is not easily implementable, so we store local
	// blocks of code for execution on a different object, and make a round trip
	// to NWScript to change OBJECT_SELF.
	public void token(NWScriptPrx proxy, NWObject self, String token, Ice.Current ice) {
		this.self = self;
		this.proxy = proxy;
		
		System.out.println("token: " + token);

		Long tok = Long.parseLong(token);
		if (tokens.containsKey(tok)) {
			Anon a = tokens.get(tok);
			try { a.e(); } catch (NotInContextException e) { } // Never going to happen.
			tokens.remove(tok);
		} else {
			System.out.println("Wanted to execute token, but not in map.");
		}

		this.self = null;
	}

	public ClientResult event(NWScriptPrx proxy, NWObject self, String event, Ice.Current ice) {
		this.self = self;
		this.proxy = proxy;

		System.out.println("event: " + event);

		// XXX: add handling/event distribution code here
		setChanged();
		notifyObservers(event);

		synchronized(delayedThunks) {
			for(Anon a : delayedThunks)
				try { a.e(); } catch (NotInContextException e) { } // Never going to happen.
			delayedThunks.clear();
		}

		this.self = null;
		return ClientResult.Continue;
	}
}
