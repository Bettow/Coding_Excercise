	void merge(int A[], int m, int B[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int last = m+n-1;
		m--;  //BUG -- first
		n--;
		while (m>=0 && n>=0) {  //test >=0
			if (A[m] > B[n]) {
				A[last--] = A[m--];
			} else {
				A[last--] = B[n--];
			}
		}
		while (m>=0) {
			A[last--] = A[m--];
		}
		while (n>=0) {
			A[last--] = B[n--];
		}
	}