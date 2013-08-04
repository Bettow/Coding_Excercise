class comp {
public:
	bool operator()(Interval l, Interval r) {
		return l.start < r.start;
	} 
};

vector<Interval> merge(vector<Interval> &intervals) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<Interval> ret;
	sort(intervals.begin(), intervals.end(), comp());
	for (int i =0; i < intervals.size(); ++i) {
		if (ret.empty()) {
			ret.push_back(intervals[i]);
			continue;
		}
		Interval last = ret.back();
		if (intervals[i].start > last.end) {
			ret.push_back(intervals[i]);
		} else {
			int b = last.start;
			int e = max(last.end, intervals[i].end);
			Interval n(b, e);
			ret.pop_back();
			ret.push_back(n);
		}
	}
	return ret;
}