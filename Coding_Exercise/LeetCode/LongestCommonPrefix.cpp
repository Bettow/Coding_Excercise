    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (strs.empty()) return "";
        int n = strs.size();
        if (n == 1) return strs[0];
        string s = strs[0];
        for (int i =0; i < s.size(); ++i) {
            char c = s[i];
            for (int j = 1; j < n; ++j) {
                if (strs[j].size() <= i || strs[j][i] != c) {
                    return s.substr(0, i);
                }
            }
        }
        return strs[0];
    }
