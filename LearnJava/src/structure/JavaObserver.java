package structure;

import java.util.Observable;
import java.util.Observer;

public class JavaObserver implements Observer {
	private Observable obs;
	public JavaObserver(Observable o) {
		this.obs = o;
		obs.addObserver(this);
	}
	
	public void update(Observable o, Object arg) {
		JavaObserable jo = (JavaObserable) o;
		//this.element = jo.getXXX();		
		
	}

}
