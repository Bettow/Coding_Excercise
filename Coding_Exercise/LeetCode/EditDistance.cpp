	int minDistance(string word1, string word2) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (word1.empty())
			return word2.size();
		if (word2.empty())
			return word1.size();
		int l1 = word1.size();
		int l2 = word2.size();
		vector<vector<int> > table(l1+1, vector<int>(l2+1, 0));
		for (int i =0; i <=l1; ++i) {
			table[i][0] = i;
		}

		for (int i = 0; i <= l2; ++i) {
			table[0][i] = i;
		}

		for (int i = 1; i <= l1; ++i) {
			for (int j = 1; j <=l2; ++j) {
				if (word1[i-1] == word2[j-1])  //BUG2
					table[i][j] = table[i-1][j-1];
				else {
					int mn = min(table[i-1][j], table[i][j-1]);  
					table[i][j] = min(mn, table[i-1][j-1]) +1;  //BUG1
				}
			}
		}
		return table[l1][l2];
	}