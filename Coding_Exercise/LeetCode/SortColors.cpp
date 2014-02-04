    //l point to the first non 0 from left
    //r point to the first non 2 from right
    void sortColors(int A[], int n) {
        int l = 0;
        int r = n-1;
        for (int i = 0; i <= r;) {
            if (A[i] == 0){
                swap(A[i], A[l]);
                i++;
                l++;
            } else if (A[i] == 1) {
                i++;
            } else {
                swap(A[i], A[r]);
                r--;
            }
        }
    }
