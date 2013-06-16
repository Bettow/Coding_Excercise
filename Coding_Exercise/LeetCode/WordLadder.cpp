int ladderLength(string start, string end, unordered_set<string> &dict) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (start.empty() || end.empty()) return 0;

	unordered_set<string> visited;
	queue<string> q;
	q.push(start);
	int level =0;
	int next_lv_count = 0;
	int curr_lv_count = 1;
	while (!q.empty()) {
		string s = q.front();
		q.pop();
		curr_lv_count--;
		for (int i = 0; i < s.size(); ++i) {
			for (int j = 0; j < 26; j++) {
				string sn = s;
				sn[i] = 'a'+j;
				if (sn == s ) continue;
				if (sn == end) return level+2;
				if (dict.find(sn) != dict.end() &&
					visited.find(sn) == visited.end()){  //use unordered_set to avoid LTE
						visited.insert(sn);  
						q.push(sn);
						next_lv_count++;
				}
			}
		}
		if (curr_lv_count==0) {
			level++;
			curr_lv_count = next_lv_count;
			next_lv_count = 0;
		}
	} 
	return 0;
}