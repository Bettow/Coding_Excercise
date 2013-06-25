package leetcode;

import java.util.Iterator;

/*next不能设为null，因为他提示我iterator给的值可能是null，然后pred可能null的返
回是true

所以这样对于T的假设是错误的，NULL对调用者可能是有意义的

正确的方法是设一个validNext的bool，看next是不是刚从iterator里拿出来的
*/

public class IteratorWrapper<T> implements Iterator<T> {
	private T tmp;
	private boolean hasNext;
	Iterator<T> it;

	IteratorWrapper (Iterator<T> it) {
		if (it.hasNext()) {
			hasNext = true;
			tmp = it.next();
		} else {
			tmp = null;
			hasNext = false;
		}
		this.it = it;
		
	}
	@Override
	public boolean hasNext() {
		return hasNext;
	}

	@Override
	public T next() {
		 if (hasNext) {
			 T t = tmp;
			 if (it.hasNext()) {
				 hasNext = it.hasNext();
				 tmp = it.next();
			 }			 			 
			 return t;
		 } else {
			 throw new NullPointerException();
		 }
	}

	@Override
	public void remove() {
		// TODO Auto-generated method stub
		
	}
	
	public T peek() {
		return tmp;		
	}
	

}
