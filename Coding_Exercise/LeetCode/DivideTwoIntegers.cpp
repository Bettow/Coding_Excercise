int divide(int dividend, int divisor) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int long long d = dividend;  //Use long long int
	int long long c = divisor;

	bool isNeg = false;
	if (d <0) {
		d = -d;
		isNeg = !isNeg;
	}

	if (c <0) {
		c = -c;
		isNeg = !isNeg;
	}

	long long int ret = 0;
	while (d >= c) {  //Don't use d > 0, use this for case 1/2
		long long int cc = c;
		int i =0;
		while (d >= cc) {
			d -= cc;
			cc = cc<<1;                
			ret += 1<<i++;                
		}
	}
	return isNeg? -ret:ret;
}
