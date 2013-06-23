//Still has a bug.  

  string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<bool> used(n, false);
        string res;
        getPermHelper(n, k, res, used);
        return res;
        
    }
    
    void getPermHelper(int n, int k, string &res, vector<bool> &used) {
        int nk = getPerm(n-1); 
        int d = (k-1)/nk+1;
        int i = 0;
        while (d) {
            if (used[i++] == false)
                d--;
        }
        used[i-1] = true;
        res.push_back(i+'0');
        if (n==1) return;
        k = k-(k-1)/(n-1) * (n-1);
        getPermHelper(n-1, k, res, used);
        
    }
    
    int getPerm(int n) {
        int r =1 ;
        while(n) 
            r *= n--;
        return r;
    }