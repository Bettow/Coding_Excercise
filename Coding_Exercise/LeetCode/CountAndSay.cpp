	string countAndSay(int n) {
    		// Start typing your C/C++ solution below
		// DO NOT write int main() function
			string s("1");
			for (int i = 0; i < n-1; ++i) {
				string res;
				for (int i = 0; i < s.size(); i++) {
					char c = s[i];
					int count = 1;
					while (i+1 < s.size() && s[i+1] == s[i]) {  //i+1
						i++;
						count++;
					}
					stringstream ss;
					ss << count;
					res = res + ss.str();   
					res.push_back(c);
				}
				s = res;
			}
			return s;
	}