int get_len(unordered_set<int> &us, int d, int dir) {
	int r = 0;
	int count = 0;
	while (us.count(d)) {
		count++;
		r = max(count, r);
		us.erase(us.find(d));
		if (dir) {
			d++;
		} else {
			d--;
		}

	}
	return r;
}
int longestConsecutive(vector<int> &num) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (num.empty())
		return 0;
	unordered_set<int> us;
	for (int i = 0; i < num.size(); ++i) {
		us.insert(num[i]);
	}
	int r = 0;
	while(!us.empty()) {
		auto i = us.begin();
		int d = get_len(us, *i+1, true) + get_len(us, *i, false);
		r = max(r, d);
	}
	return r;

}
