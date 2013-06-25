package leetcode;

import java.util.Iterator;

/*next������Ϊnull����Ϊ����ʾ��iterator����ֵ������null��Ȼ��pred����null�ķ�
����true

������������T�ļ����Ǵ���ģ�NULL�Ե����߿������������

��ȷ�ķ�������һ��validNext��bool����next�ǲ��Ǹմ�iterator���ó�����
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
