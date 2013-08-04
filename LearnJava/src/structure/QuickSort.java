package structure;

import java.util.ArrayList;

public class QuickSort {

	public int quickSort(ArrayList<Integer> iv) {
		int p = iv.get(0);
		int s = 0;
		int f = iv.size()-1;
		for (int i = 0; i < iv.size();) {
			int n = iv.get(i);
			if (n < p) {
				iv.set(i, iv.get(s));
				iv.set(s, n);
				s++;
				i++;
			} else if (n >p) {
				iv.set(i, iv.get(f));
				iv.set(f, n);
				f--;
			} else {
				i++;
			}	
		}
		return p;
	}
}
