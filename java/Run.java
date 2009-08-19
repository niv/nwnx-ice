import NWN.*;

class Run {
	public static void main(String[] va) {
		Ice.Communicator ic = Ice.Util.initialize();
		Ice.ObjectAdapter adapter = ic.createObjectAdapterWithEndpoints(
			"Client", "default -p 5223");
		ClientI c = new ClientI();
		_ClientTie tie = new _ClientTie(c);
		Ice.Object obj = tie;
		adapter.add(obj, ic.stringToIdentity("Client"));
		adapter.activate();

		// instanciate one observer, this is for example purposes only
		// Use whatever event framework you see fit.

		Example e = new Example();
		c.addObserver(e);

		System.out.println("All active, listening ..");
	}
}
