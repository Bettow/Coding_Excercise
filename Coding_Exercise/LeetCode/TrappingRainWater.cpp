	int trap(int A[], int n) {
		if (!A || !n) return 0;

		int mid = 0; 
		for (int i = 0; i < n; ++i)
			if (A[i] > A[mid]) mid = i;

		int water = 0, h = 0;
		for (int i = 0; i < mid; ++i)
			if (h > A[i]) 
				water += h - A[i];
			else h = A[i];

		h = 0;
		for (int i = n - 1; i > mid; --i)
			if (h > A[i]) 
				water += h - A[i];
			else h = A[i];

		return water;
	}