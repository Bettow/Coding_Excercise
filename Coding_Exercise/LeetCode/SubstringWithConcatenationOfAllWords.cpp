vector<int> findSubstring(string S, vector<string> &L) {
    // Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<int> ret;
	if (S.empty() || L.empty())
		return ret;
	unordered_map<string, int> target;
	for (int i =0; i < L.size(); ++i) {
		target[L[i]]++;
	}

    	int n = S.size();  //using s.size() in the loop would cause a bug as S.size() is size_t
	int nl = L.size();
	int ll = L[0].size();
	for (int i =0; i<= n - ll*nl ; i++) {
		unordered_map<string, int> c(target);
		string curr_s = S.substr(i, ll);
		if (target.count(curr_s)){
			int j=0;
			for (; j < nl; j++) {
				string cs = S.substr(i+j*ll, ll);
				c[cs]--;
				if (c[cs] <0) break;
			}
			if (j == nl) {
				ret.push_back(i);
			}
		}
	}
	return ret;
}
