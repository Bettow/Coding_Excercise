	vector<int> plusOne(vector<int> &digits) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int carry = 1;
		int n = digits.size();
		vector<int> result(n,0);
		for (int i = n-1; i>=0; --i) {
			int sum = digits[i]+carry;
			result[i] = sum%10;
			carry = sum/10;
		}
		if (carry) {
			result.insert(result.begin(), 1);
		}
		return result;

	}