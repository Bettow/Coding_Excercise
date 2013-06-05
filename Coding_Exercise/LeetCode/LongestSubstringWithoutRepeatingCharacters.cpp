	int lengthOfLongestSubstring(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (s.empty())
			return 0;

		int slow=0, fast=0;
		int result = 0;
		vector<bool> exist(256,false);
		while(fast < s.size()){
			if (exist[s[fast]]) {
				result = max(result, fast-slow);
				while(s[slow] != s[fast]){
					//reset slow to the  first duplcated elements								
					exist[s[slow]] = false;  //BUG1
					slow++;
				}
				slow++;
				fast++;
			} else {
				exist[s[fast]]= true;  //BUG2
				fast++;
			}
		}
		result = max(result, fast-slow);
		return result;      
	}