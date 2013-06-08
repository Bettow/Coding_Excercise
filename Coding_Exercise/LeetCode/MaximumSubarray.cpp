	int maxSubArray(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (n==0) return 0;
		int sum = 0;
		int max = -1 * INT_MAX;

		for (int i=0; i<n; i++) {

			sum += A[i];
			if (sum > max) max = sum;
			if (sum < 0) sum = 0;
		}
		return max;

	}