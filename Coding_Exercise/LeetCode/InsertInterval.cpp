    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = intervals.size();
        int i = 0;
        vector<Interval> ret;
        while (i < n && intervals[i].end < newInterval.start)
            ret.push_back(intervals[i++]);
        
        //Interval nv;
        while (i < n && intervals[i].start <= newInterval.end) {
            //bug nv will be rewritten in every loop
            //nv.start = min(intervals[i].start, newInterval.start);
            //nv.end = max(intervals[i].end, newInterval.end);
            newInterval.start = min(intervals[i].start, newInterval.start);
            newInterval.end = max(intervals[i].end, newInterval.end);
            i++;
        }
        //ret.push_back(nv);
        ret.push_back(newInterval);
        
        while (i<n)
            ret.push_back(intervals[i++]);
        
        return ret;
    }