	void sortColors(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int l = -1;
		int r = n;
		for (int i = 0; i < r;) {  //BUG
			if (A[i] == 0) {
				l++;
				swap(A[i], A[l]);
				i++;
			} else if (A[i] == 2) {
				r--;
				swap(A[i], A[r]);
			} else {
				i++;
			}

		}
	}