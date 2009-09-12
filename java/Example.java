import java.util.*;
import NWN.*;

class Example implements Observer {
	public void update(Observable o, Object arg) {
		try {
		final ClientI c = (ClientI)o;
		final String event = (String)arg;
		final NWObject self = c.getObjectSelf();

		System.out.println("Observer got event: " + event);
		final String name = c.getProxy().getName(self, false);
		System.out.println("name of objectSelf: " + name);
		
		// Call nwscript here as you see fit.

		// Highly contrived example code.
		if (event.equals("creature_perception")) {
			final NWObject perceived = c.getProxy().getLastPerceived();


			// Sucks that Java doesn't support proper closures.
			// This will do as an example, though.
			c.assign(perceived, new Anon() {
				public void e() throws NotInContextException {
					c.getProxy().speakString("I can see " + name, TalkVolume.TalkVol);
				}
			});
		}

		} catch (NotInContextException e) {
			// This will be thrown by the ICE remote endpoint if
			// you try to call NWScript while no event is running.
			// Doing that would corrupt the VM stack and segfault your
			// sorry arse.
		}
	}
}
