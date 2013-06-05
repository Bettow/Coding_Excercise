	bool isPalindrome(int x) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (x < 0) return false;
		if (x==0) return true;

		int div = 1;
		while (x/div >=10) {
			div *= 10;  //use divident
		}

		while (x) {
			int l = x/div;
			int r = x%10;
			if (l != r) return false;
			x = (x-div*l) /10;
			div /= 100;
		}
		return true;

	}