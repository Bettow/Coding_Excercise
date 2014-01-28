    int removeDuplicates(int A[], int n) {
        if (n ==0)
            return 0;
        int slow = 0;
        for (int i = 1; i < n; ++i) {
            if (A[i] != A[slow]) {
                A[++slow] = A[i];
            }
            
        }
        return slow+1;
    }
