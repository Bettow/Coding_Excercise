    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <=2) return n;
        int p = 2;
        for (int i =2; i <n; ++i) {
            if (A[i] == A[p-1] && A[i] == A[p-2]) //BUG use A[p-1] not i
                continue;
            A[p++] = A[i];
        }
        return p;
    }