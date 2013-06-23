int searchInsert(int A[], int n, int target) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (n==0) return 0;
	if (target < A[0]) {
		return 0;
	} else if (target > A[n-1]) {
		return n;
	}

	int l = 0;
	int r = n-1;
	while (l <=r ) {
		int m = (l+r)/2;
		if (A[m] == target) {
			return m;
		} else if (A[m] > target) {
			r = m-1;
		} else {
			l = m+1;
		}
	}
	return l;
}