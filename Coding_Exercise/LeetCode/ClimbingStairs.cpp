	int climbStairs(int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int p1= 2;  //BUG!!!
		if (n ==1)  return 1;
		int p2 =1 ;
		if (n ==2) return 2;
		int result =0;
		for (int i = 3; i <=n; ++i) {
			result = p1+p2;
			p2 = p1;   //BUG!!!
			p1 = result;
		}
		return result;
	}