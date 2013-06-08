    	//LTE in large test cases, rewrite later in DP
	bool isMatch(const char *s, const char *p) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (!*s && !*p) return true;
		if (*p == '*') {  //BUG
            			const char *k =p;
            			while (*k=='*') k++;
            			if (*k =='\0')
                				return true;
		} 
        
		if (!*s || !*p) return false;

		if (*p != '*') {
			if (*s == *p || *p == '?')
				return isMatch(s+1, p+1);
			else 
				return false;
		} else {
			const char *k =s;
			bool b = false;
			while (*k) {
				b = b || isMatch(k, p+1);
				k++;
			}
			return b;
		}

	}