	vector<int> findSubstring(string S, vector<string> &L) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<int> result;
		map<string, int> words;
		map<string, int> curs;

		for (int i =0; i < L.size(); ++i) {
			words[L.at(i)]++;
		}

		int M = L.size(); //m words
		if (M == 0) return result;
		int N = L.at(0).size(); //n size word
		for (int i = 0; i <= S.size() -M*N; ++i) {
			curs.clear();
			int j = 0;
			for (j = 0; j < M; ++j) { 
				string word = S.substr(i + j*N, N);
				if (words.find(word) == words.end()) {
					break;
				} else {
					curs[word]++;
				}
				if (curs[word]> words[word])
					break;
			}
			if (j == M)
				result.push_back(i);
		}
		return result;
	}