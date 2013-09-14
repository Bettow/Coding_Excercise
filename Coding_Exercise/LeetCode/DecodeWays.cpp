    bool validOne(char c) {
        return '0' < c && c <= '9';
    }
    bool validTwo(char c1, char c2) {
        if (c1 == '1' && '0' <= c2 && c2 <= '9')
            return true;
        if (c1 == '2' && '0' <= c2 && c2 <= '6')
            return true;
        return false;
    }
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.empty())
            return 0;
        int n = s.size();
        if (n == 1)
            return validOne(s[0]);
        if (n ==2) {
            int k1 = validOne(s[0]) && validOne(s[1]);
            int k2 = validTwo(s[0], s[1]);
            return k1+ k2;
        }
        int k1 = validOne(s[0]) && validOne(s[1]);
        int k2 = validTwo(s[0], s[1]);
        int s2 = validOne(s[0]);
        int s1 = k1+k2;
        int sum = 0;
        for (int i = 2; i < n; ++i) {
            sum = s1* validOne(s[i]) + s2*validTwo(s[i-1],s[i]);
            s2 = s1;
            s1 = sum;
        }
        return sum;
    }
	
