	int firstMissingPositive(int A[], int n) 
	{
		for (int i=0; i<n; ++i)
			while (1<=A[i] && A[i] <=n && A[A[i]-1]!=A[i])
				swap(A[i], A[A[i]-1]);

		for (int i=0; i<n; ++i)
			if (A[i] != i+1)
				return i+1;

		return n+1;   
	}