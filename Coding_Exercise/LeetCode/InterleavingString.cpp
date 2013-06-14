bool isInterleave(string s1, string s2, string s3) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int ss1 = s1.size();
	int ss2 = s2.size();
	int ss3 = s3.size();

	if (ss3 != ss1+ss2)
		return false;

	vector<vector<bool> > match(ss1+1, vector<bool>(ss2+1, false));
	match[0][0] = true;
	for (int i =1; i<= ss1; ++i) {
		if (s1[i-1] == s3[i-1])
			match[i][0] = true;
		else
			break;
	}
	for (int i = 1; i <= ss2; ++i) {
		if (s2[i-1] == s3[i-1])
			match[0][i] = true;
		else
			break;
	}

	for (int i = 1; i <= ss1; ++i) {
		for (int j = 1; j <= ss2; ++j) {
			char c1 = s1[i-1];
			char c2 = s2[j-1];
			char c3 = s3[i+j-1];
			if (c1 == c3)
				match[i][j] = match[i-1][j] || match[i][j];
			if (c2== c3)
				match[i][j] = match[i][j-1] || match[i][j];

		}


	}
	return match[ss1][ss2];


}