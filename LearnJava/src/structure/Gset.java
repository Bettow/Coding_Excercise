package structure;

import java.util.HashSet;

public class Gset<K> extends HashSet<K> {
	
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public void insert(K e) {
		super.add(e);
	}
	public void delete(K e) {
		super.remove(e);
	} 
	
	public int rquery() {
		int s = super.size();
		int rd = (int)Math.random()*s;
		return 0;
	}

}
