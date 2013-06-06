	int removeDuplicates(int A[], int n) {
		if (n==0)
			return 0;

		int slow =0;
		int fast =1;
		while (fast <n) {
			if (A[fast] != A[slow]) {
				A[++slow] = A[fast];			
			}
			fast++;
		}
		return slow+1;
	}