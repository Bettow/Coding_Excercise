	bool isScramble(string s1, string s2) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (s1.empty() || s2.empty())
			return false;

		if (s1.size() != s2.size())
			return false;

		int n = s1.size();

		bool t[n][n][n];

		for (int i=0; i<n; i++)  //notice this
			for (int j=0; j<n; j++)
				t[i][j][0] = s1[i] == s2[j];

		for (int l = 1; l < n; ++l) {
			for (int i = 0; i+l < n; ++i) {
				for (int j = 0; j+l < n; ++j) {  //l is numbers
					t[i][j][l] = false;
					for (int k = 0; k <l; ++k) {
						if ((t[i][j][k] && t[i+k+1][j+k+1][l-k-1]) ||
							(t[i][j+l-k][k] && t[i+k+1][j][l-k-1]))
						{
							t[i][j][l] = true;
							break;

						}
					}
				}        
			}
		}
		return t[0][0][n-1];  //notice return;
	}
