string getPermutation(int n, int k) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<int> vi(n);
	int perm = 1;
	for (int i =0; i < n; ++i) {
		vi[i] = i+1;
		perm *= i+1;
	}
	string ret;
	for (int i =n; i>0; --i) {
		perm = perm/i;
		int q = (k-1)/perm;
		k = k - q*perm;
		ret += '0' + vi[q];
		vi.erase(vi.begin()+q);
	}
	return ret;
}