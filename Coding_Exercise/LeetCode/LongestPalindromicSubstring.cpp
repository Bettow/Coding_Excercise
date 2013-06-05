	string expandPal(string s, int l1, int l2) {
		while (l1>=0 && l2 < s.size() && s[l1]== s[l2]) {
			l1--;
			l2++;
		}
		l1++;  //Old bug 1 forget to revert back
		l2--;
		return s.substr(l1, l2-l1+1);
	}
	string longestPalindrome(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (s.size() == 1) return s;
		string result;
		if (s.empty())  return result;

		for (int i =0; i < s.size()-1; ++i) {
			string ns = expandPal(s, i, i);  //BUG1 reused var
			if (ns.size() > result.size())
				result = ns;
			ns = expandPal(s, i, i+1);
			if (ns.size() > result.size())
				result = ns;

		}
		return result;

	}