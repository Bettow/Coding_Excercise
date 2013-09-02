bool isMatch(const char *s, const char *p) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (!s && !p) return true;

	const char *s_s;
	const char *p_s;
	while (*s) {
		if (*p == '?' || *p == *s) {
			p++;
			s++;
		} else if (*p == '*') {
			while (*p == '*') {
				p++;
			}
			if (! *p) return true;
			s_s = s;
			p_s = p;
		} else if ((!*p || *p != *s) && p_s) {
			s = ++s_s;
			p = p_s;
		} else {
			return false;
		}
	}

	while (*p) {
		if (*p != '*')
			return false;
		p++;
	}
	return true;
}


//recursion
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (*p == '*') {
            while (*p == '*') p++;
            if (*p == '\0') {
                return true;
            } else {
                while (*s && !isMatch(s, p)) {
                    s++;
                }
                return *s; // above loop end because of s is end;
            }
        } else if (*p == '\0' || *s == '\0') {
            return *p == *s;
        } else if (*p == *s || *p == '?') {
            return isMatch(s+1, p+1);
        } else {
            return false;
        }
    }
