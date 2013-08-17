    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n= num.size();
        if (n <3)
            return 0;
        sort(num.begin(), num.end());
        int closest = INT_MAX;
        int ret = 0;
        for (int l = 0; l < n-2; l++) {
            int pl = l+1;
            int pr = n-1;
            while (pl < pr) {
                int sum = num[l] +num[pl] + num[pr];
                int dist = abs(sum-target);
                if (dist == 0) return target;
                if (dist< closest) {
                    closest = dist;
                    ret = sum;
                }
                if (sum > target) {
                    pr--;
                } else {
                    pl++;
                }
            }
        }
        return ret;
    }
