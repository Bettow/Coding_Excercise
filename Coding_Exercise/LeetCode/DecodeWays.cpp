    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.empty())
            return 0;
            
        int n = s.size();
        vector<int> tb(n+1,1);
        if (s[0] == '0')
            return 0;
        for (int i = 1; i <= n; i++) {
            if (s[i-1] == '0') {
                if ( !(s[i-2] == '1' || s[i-2]=='2')) { 
                    return 0;
                } else {
                    tb[i]= tb[i-2];
                }
            } else if (i >= 2 && (('0' < s[i-1] && s[i-1] <='6' && s[i-2]=='2') ||
                 (s[i-2] == '1'))) {
                    tb[i] = tb[i-1] + tb[i-2];
            } else {
                    tb[i] = tb[i-1];
            }  
            
        }
        return tb[n];
        
    }



//2
	int numDecodings(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (s.empty())
			return 0;
		vector<int> iv(s.size()+1,0);

		if (s[0] =='0') {  //BUG
			iv[0] =0;
		} else {
			iv[0]=1;
		}

		for (int i =1; i<= s.size(); i++) {
			int c1=0;
			if (s[i-1] != '0')  //there could be no way to decode the string
				c1= iv[i-1];
			int c2=0;
			if (i>=2 && (s[i-2] == '1' ||(s[i-2]=='2' && s[i-1] <='6')))
				c2 = iv[i-2];
			iv[i] = c1+c2;
		}
		return iv[s.size()];
	}
	