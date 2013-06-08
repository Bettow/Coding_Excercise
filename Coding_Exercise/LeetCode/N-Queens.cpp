class Solution {
public:
    vector<bool> usedCol;
    vector<int> res;
    vector<vector<string> > ret;
    bool check(int depth, int y) {
        for (int i =0; i < depth; ++i) {
            if (abs(depth -i) == abs(y- res[i]))
                return false;            
        }
        return true;
    }

    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        usedCol.clear();
        usedCol.resize(n, false);
        res.clear();
        res.resize(n,0);
        ret.clear();
        dfs(0, n);
        return ret;
    }
    
    void dfs(int depth, int n){
        if (depth ==n) {
            vector<string> ans;
            for(int i = 0; i < n; i++){
                string s;
                for(int j = 0; j < res[i]; j++)
                    s += '.';
                s += 'Q';
                for(int j = 0; j < n - (res[i] + 1); j++)
                    s += '.';
                ans.push_back(s);
            }
            ret.push_back(ans);
            return;
        }
        
        for (int i = 0; i < n; i++) {
            if (usedCol[i] || !check(depth, i)) continue;  //notice OR here
            usedCol[i] = true; 
            res[depth] = i; //dont' forget res!   
            dfs(depth+1, n);
            usedCol[i] = false;
            
        } 
    }
};