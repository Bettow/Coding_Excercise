    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ret(n, vector<int>(n, 0));
        
        int l = 0;
        int r = n-1;
        
        int num = 1;
        while (l <=r) {
            for (int i = l; i <= r; ++i) {
                ret[l][i] = num++;
            }
            
            for (int i = l+1; i <= r; ++i) {
                ret[i][r] = num++;
            }
            
            for (int i = r-1; i >= l; --i) {
                ret[r][i] = num++;
            }
            
            for (int i = r-1; i > l; --i) {
                ret[i][l] = num++;
            }
            l++;
            r--;
        }
        
        return ret;
    }
