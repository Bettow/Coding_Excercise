	int minCut(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int n = s.size();
		vector<vector<bool> > isPal(n, vector<bool>(n, false));
		for(int i = 0; i < n; ++i) {
			isPal[i][i] = true;
		}
		for(int i = 1; i < n; ++i) {
			isPal[i][i-1] = (s[i-1] == s[i]);
		}
		for(int i = 2; i < n; ++i) {
			for (int j = 0; j < i-1; ++j) {
				isPal[i][j] = isPal[i-1][j+1] && (s[i] == s[j]);
			}
		}

		//check
		vector<int> tb(s.size(), 0);
		for (int i = 0; i < tb.size(); ++i) {  //BUG 1 initialization
			tb[i] =i;
		}
		for (int i = 0; i < n; ++i) {
			if (isPal[i][0])
				tb[i]= 0;
			else {
				for (int j = 1; j<=i; ++j) {
					if (isPal[i][j] && tb[i] > tb[j-1]+1) {
						tb[i]= tb[j-1]+1;
					} 
				}
			}

		}
		return tb[n-1];

	}