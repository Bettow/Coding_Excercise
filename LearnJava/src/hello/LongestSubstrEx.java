package hello;

public class LongestSubstrEx {
	public String LongestSub(String s) {
		char first = '0';
		char second = '0';
		int loc[] = {0, 0} ;

		int fast = 0;
		int slow = 0;
		String ret = new String();
		int retLength = 0;
		while (fast < s.length()) {
			if (first == '0') 
				first = s.charAt(fast);
			char c = s.charAt(fast);
			if (c == first) {
				first = second;
				second = c;
				loc[0] = loc[1];
				loc[1] = fast;
			} else if (c == second) {
			} else {
				slow = loc[1];
				loc[0] = loc[1];
				loc[1] = fast;
				first = second;
				second = c;
			}
			fast++;
			int dist = fast - slow;
			if (dist > retLength) {
				retLength = dist;
				ret = s.substring(slow, fast);
			}
		} 
		return ret;
	}
	
	public static void main(String arg[]) {
		LongestSubstrEx o = new LongestSubstrEx();
		o.LongestSub("abcabbac");
	}

}
