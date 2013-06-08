	struct comp {
		bool operator()(const Interval &l, const Interval &r) {
			return l.start < r.start;
		}
	};
	bool mergeInterval(const Interval &l, const Interval &r, Interval &out) {
		if (l.end < r.start)
			return false;
		out.start = l.start;
		out.end = max(l.end, r.end); //BUG1
		return true;    

	}
	vector<Interval> merge(vector<Interval> &intervals) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<Interval> ret;
		if (intervals.empty())
			return ret;

		sort(intervals.begin(), intervals.end(), comp());  //comp()
		ret.push_back(intervals[0]);
		for (int i=1; i< intervals.size(); ++i) {
			Interval out;
			if (mergeInterval(ret.back(), intervals[i], out))
				ret.back() = out;
			else
				ret.push_back(intervals[i]);

		}
		return ret;
	}