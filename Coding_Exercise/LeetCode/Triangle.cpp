int minimumTotal(vector<vector<int> > &triangle) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<int> iv(triangle[triangle.size()-1].size(), 0);
	iv[0] = triangle[0][0];
	for (int i = 1; i < triangle.size(); ++i) {
		for (int j= 0 ; j <= i ; ++j) {
			if (j ==0) {
				iv[0] += triangle[i][0]; 
			} else if (j ==i) {
				iv[j] = iv[j-1] + triangle[i][j];
			} else {
				iv[j] = min(iv[j-1], iv[j]) + triangle[i][j];
			}
		}
	}

	int ret = INT_MAX;
	for (int i =0; i < iv.size(); i++) {
		ret = min(ret, iv[i]);
	}
	return ret;
}