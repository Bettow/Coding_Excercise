    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
        vector<string> ret;
        if (n <4 || n> 12)
            return ret;
        
        string res;
        dfs(s, 0, res, ret);
        return ret;
        
    }
    
    void dfs(string rem, int lv, string res, vector<string> &ret) {
        if (rem.empty() && lv == 4) {
            ret.push_back(res);
            return;
        }
        
        for (int i = 1; i<=3; i++) {
            if (rem.size() <i) return; //must check
            string s = rem.substr(0, i);
            string r = rem.substr(i, rem.size()-i);
            if (isValidIP(s)) {
                string resTmp;
                if (lv == 3)
                    resTmp = res+s;
                else 
                    resTmp = res+s + '.';
                
                dfs(r, lv+1, resTmp, ret);
            }
        }
    }
    
    bool isValidIP(string s) {
        if (s[0] == '0' && s.size() >1)
            return false;
        
        stringstream ss(s);
        int d;
        ss >>d;
        if (d >=0 && d <=255)
            return true;
        return false;
        
    }