int lengthOfLongestSubstring(string s) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int ret =0;
	unordered_set<char> usc;
	int i =0;
	int l = 0;
	for (; i < s.size(); ++i) {
		char c = s.at(i);
		if (usc.count(c)) {
			ret = max(ret, i-l);
			while (s[l] != c) {
				usc.erase(s[l]);
				l++;
			}
			l++;
		} else {
			usc.insert(c);
		}
	}
	ret = max(ret, i-l);
	return ret;
}