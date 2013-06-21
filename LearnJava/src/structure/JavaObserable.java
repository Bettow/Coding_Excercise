package structure;

import java.util.Observable;
import java.util.Observer;

public class JavaObserable extends Observable {
	public void dataChanged() {
		setChanged();
		notifyObservers();
	}
	
}
