class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;
        helper(s, 0, 0, "", ret);
        return ret;
    }
    
    void helper(string s, int p, int count, string curr, vector<string> &ret) {
        if (p == s.size() && count == 4) {
            ret.push_back(curr);
            return;
        }
        if (count >=4) return;
        for (int i = 1; i <= 3 && i+p <= s.size(); ++i) {
            string rs = s.substr(p, i);
            if (isValidIP(rs)) {
			    if (count == 0)
				    helper(s, p+i, count+1, rs, ret);
			    else
				    helper(s, p+i, count+1, curr+"."+rs, ret);
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
};
