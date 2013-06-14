    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        if (S.empty())
            return ret;
        sort(S.begin(), S.end());
        vector<int> res;
        dfs(S, res, 0, ret);
        return ret;
    }
    
    void dfs(vector<int> &S, vector<int> res, int begin, vector<vector<int> > &ret) {
        ret.push_back(res);
        
        for (int i = begin; i < S.size(); ++i) {
            if (i != begin && S[i] == S[i-1]) continue;
            res.push_back(S.at(i));
            dfs(S, res, i+1, ret);
            res.pop_back();
        }
    }