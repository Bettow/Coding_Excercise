
	int jump(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		if (n == 1) return 0;

		int left =0;
		int right = A[0];
		if (right >=n-1) return 1;  //BUG
		int step = 0;
		while (left <= right) {
			step++;
			int furthestSoFar =0;
			for (int i = left; i<=right; ++i) {
				furthestSoFar = max(furthestSoFar, A[i]+i);
				if (furthestSoFar >= n-1) return step+1;

			}
			left = right+1;
			right = furthestSoFar;

		}
		return step+1;

	}