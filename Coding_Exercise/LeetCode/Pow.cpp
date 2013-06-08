	double pow(double x, int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (n == 0) return 1;
		if (x == 0) return 0;

		bool isNeg = false;
		if (n <0) {
			isNeg = true;
			n = -n;
		}	

		double hp = pow(x, n/2);

		double result;
		if (n%2 ==0) {
			result = hp*hp;
		} else {
			result = hp*hp*x;
		}

		return isNeg ==false? result: 1/result;

	}