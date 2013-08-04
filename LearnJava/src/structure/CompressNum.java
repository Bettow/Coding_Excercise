package structure;

import java.util.ArrayList;

public class CompressNum {
	private class Pair {
		private int num;
		private int count;
		public Pair(int n, int c) {
			num = n;
			count = c;
		}
		
		public int getNum() {
			return num;
		}
		
		public int getCount() {
			return count;
		}
	}
	
	private ArrayList<Pair> mList;
	public CompressNum() {
		mList = new ArrayList<Pair>();
	}
	
	public void compressNum(int n) {
		String s = Integer.toString(n);
		int ct = 1;
		for (int i =0; i < s.length();) {
			char c = s.charAt(i);
			while (i+1 < s.length() && s.charAt(i+1) ==  c) {
				ct++;
				i++;
			}
			Pair p = new Pair(c, ct);
			mList.add(p);
			i++;
		}
	}
	
	public void 
}
