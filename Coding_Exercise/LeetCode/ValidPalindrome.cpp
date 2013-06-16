bool isPalindrome(string s) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int l = 0;
	int r = s.size()-1;
	while (l <r) {
		while(l < s.size() && !(isalpha(s[l]) || isdigit(s[l]))) l++;
		while(r > 0 && !(isalpha(s[r]) || isdigit(s[r]))) r--;
		if (l>=r) return true;  //check here
		char lc = s[l];
		char rc = s[r];
		if (lc == rc || abs(lc-rc) == 32)  {        
			l++;
			r--;
		} else 
			return false;
	}
	return true;       
}