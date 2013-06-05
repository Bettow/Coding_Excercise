	string longestCommonPrefix(vector<string> &strs) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (strs.empty())
			return ("");
		if (strs.size() ==1) {
			return strs[0];
		}

		int i =0;
		bool isFound = false;
		for (i =0; i < strs[0].size(); ++i) {
			for (int j =1; j < strs.size(); ++j) {
				if (i >= strs[j].size() || strs[j][i] != strs[0][i]) {
					isFound = true;
					break;
				}
			}
			if (isFound == true)
				break;
		}

		//if (isFound) i--;  //BUG1
		if (i ==0)
			return ("");
		else {
			return strs[0].substr(0, i);
		}
	}