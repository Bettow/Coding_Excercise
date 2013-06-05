	int reverse(int x) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (x == 0) return 0;
		bool isNegative = false;
		if (x < 0) {
			isNegative = true;
			x = -x;
		}

		int result = 0;
		while (x > 0) {
			int d = x%10;
			result = result*10 + d;
			x /= 10;
		}

		return isNegative? -result:result;
	}