package structure;

import java.util.ArrayList;

public class ObData implements Observable {
	private ArrayList<Observer> obs;
	boolean changed = false;

	public void setChanged() {
		changed = true;
	}
	@Override
	public void registerObserver(Observer o) {
		obs.add(o);		
	}

	@Override
	public void removeObserver(Observer o) {
		if (obs.contains(o))
			obs.remove(o);
		
/*		int i = obs.indexOf(o);
		if (i >=0)
			obs.remove(i);*/
				
	}

	@Override
	public void notifyObserver() {
		if (changed) {
			for (Observer o : obs) {
				o.update();
			}
		}
		changed = false;
	}

}
