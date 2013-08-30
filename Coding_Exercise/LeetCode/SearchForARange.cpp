    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int s = -1;
        int l = 0;
        int r = n-1;
        while (l <=r) {
            int mid = (r+l)/2;
            if (A[mid] < target) {
                l = mid+1;
            } else if (A[mid] > target) {
                r = mid-1;
            } else {
                r = mid-1;
                s = mid;
            }
        }
        vector<int> res(2, -1);
        if (s == -1) {
            return res;
        }
        res[0] = s;
        l =0;
        r = n-1;
        s = -1;
        while (l <=r) {
            int mid = (r+l)/2;
            if (A[mid] < target) {
                l = mid+1;
            } else if (A[mid] > target) {
                r = mid-1;
            } else {
                l = mid+1;
                s = mid;
            }
        }
        res[1] = s;
        return res;
    }
