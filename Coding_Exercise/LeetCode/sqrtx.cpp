    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x <=1) return 1;//bug
        int l = 0;
        int r = x;
        while ((r-l) >1) {
            int mid = l + (r-l)/2;
            int d = x/mid;
            if (d == mid)
                return d;
            else if (d > mid) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
        
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