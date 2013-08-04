package hello;

import java.util.ArrayList;
import structure.QuickSort;

public class KPartition {
	ArrayList<Integer> KParition(ArrayList<Integer> iv, int k) {
		QuickSort s = new QuickSort();
		int e = s.quickSort(iv);
		int p = iv.indexOf(e);
		int rightPart = iv.size()-1-p;
		if (rightPart > k ) 
			return KParition(ArrayList<Integer> iv,  
		
		return iv;
	} 

}
