	char *strStr(char *haystack, char *needle) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (*needle == '\0')
			return haystack;

		while (*haystack) {
			char *curr = haystack;
			char *n = needle;  //BUG3 reset needle;
			while (*curr && *n && *curr == *n) { 
				curr++;
				n++;
			}
			if (*n == '\0')  //BUG2 only test needle
				return haystack;          
			haystack++;

		}
		return NULL;
	}
	

//KMP
vector<int> prefix_function(string needle) {
	vector<int> ret(needle.size(), 0);

	int k = 0;
	for (int i = 1; i < needle.size(); ++i) {
		while (k > 0 && needle[i] != needle[k]) {
			k = ret[k - 1];
		}
		if (needle[i] == needle[k]) {
			k++;
		}
		ret[i] = k;
	}
	return ret;
}

char *strStr(char *haystack, char *needle) {
	if (*needle == '\0')
		return haystack;
	string s(needle);
	string h(haystack);
	int q = 0;
	vector<int> next = prefix_function(s);
	for (int i = 0; i < h.size(); ++i) {
		while (q > 0 && s[q] != h[i]) q = next[q-1];
		if (s[q] == h[i]) ++q;
		if (q == s.size()) {
			return haystack + i + 1 - q;
		}
	}
	return NULL;

}
