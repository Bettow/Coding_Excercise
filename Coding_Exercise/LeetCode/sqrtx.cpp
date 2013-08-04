    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long int l = 0;
        long long int r = x;
        long long int xx = x;
        while (l <=r) {
            long long int m = (l+r)/2;
            if (m*m <= xx && (m+1)*(m+1) > xx) {
                return m;
            } else if (m*m > xx) {
                r = m-1;
            } else {
                l = m+1;
            }
        }
    }

	double sqrt(int x) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() 
		if (x <=0) return 0;
		double precision = 0.001;
		int result;

		double ix = x;
		double xo = ix/2;
		double diff = xo;
		double x1;
		while (diff > precision) {
			x1 = (xo + ix/xo) /2 ;
			diff = abs(x1-xo);
			xo = x1;
		} 

		return xo;
	}
