package hello;

import java.util.ArrayList;

public class FindPrime {
	public ArrayList<Integer> findPrime(int n) {
		boolean [] tb = new boolean[n];
		for (int i  = 2; i < n; i++) {
			tb[i] = true;
		}	
		for (int i = 2; i < n; ++i) {
			if (tb[i] == true) {
				for (int j = i*i; j < n; j +=i) {
					tb[j] = false;
				}
			}
		}
		
		ArrayList<Integer> ret = new ArrayList<Integer>();
		for (int i =2; i < n; ++i) {
			if (tb[i] == true)
				ret.add(i);
		}
		return ret;
	}

}
