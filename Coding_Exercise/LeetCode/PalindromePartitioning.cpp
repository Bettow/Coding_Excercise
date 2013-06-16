typedef vector<vector<string>> vvs;
	vector<vector<string>> partition(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vvs result;
		vector<string> res;
		dfs(s, res, result);
		return result;
	}

	void dfs(string remain, vector<string> res, vvs &result){
		if (remain.empty()) {
			result.push_back(res);
			return;
		}

		for(int i=1; i <= remain.size(); ++i) {
			string subs = remain.substr(0, i);
			if (!isPalid(subs)) continue;
			res.push_back(subs);
			string rem = remain.substr(i,remain.size()-i);
			dfs(rem, res, result);
			res.pop_back();
		}
	}

	bool isPalid(string s) {
		int l= 0;
		int r = s.size()-1;
		while (l < r) {
			if (s[l] != s[r]) return false;
			l++;
			r--;
		}
		return true;
	}