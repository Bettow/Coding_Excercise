//Large test case LTE

typedef map<string, vector<string> > msv;
void generateResult(msv mp, string start, string end, vector<vector<string> > &result, vector<string> res ) {
	if (end == start)  {
		reverse(res.begin(), res.end());
		result.push_back(res);
		return;
	}
	for (vector<string>::iterator iter = mp[end].begin(); iter != mp[end].end(); ++iter) {
		res.push_back(*iter);
		generateResult(mp, start, *iter, result, res );
		res.pop_back();
	}

}

vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {  //use unordered set

	vector<vector<string> > result;
	msv mp_str_v;
	queue<string> curr_q;
	curr_q.push(start);
	mp_str_v[start].push_back("");  //Fix start
	queue<string> next_q;

	queue<string> curr_q_bk;
	bool isFound = false;
	unordered_set<string> us;  //
	while (!curr_q.empty()) {
		string word = curr_q.front();
		curr_q.pop();
		for (int i =0; i < word.size(); ++i) {
			for (int j = 0; j < 26; ++j) {
				string new_word(word);
				char c = j + 'a';
				if (c == word[i]) continue;
				new_word[i] = c;		
				if (dict.find(new_word) == dict.end()) continue; //not in dict
				if (mp_str_v.find(new_word) == mp_str_v.end()) {
					if (new_word == end) isFound =true;
					next_q.push(new_word);
					us.insert(new_word);
					mp_str_v[new_word].push_back(word);
				} else if (us.find(new_word) != us.end()){  //New word has more than one father. Remember this condition 
					mp_str_v[new_word].push_back(word);
				}
			}
// 			if (isFound)
// 				break;
		}
		if (curr_q.empty()) {
			if (isFound) {
				vector<string> res;
				res.push_back(end);
				generateResult(mp_str_v, start, end, result, res );
				break;
			} else 	
				curr_q.swap(next_q);
				us.clear();  //used to store words in the same level
		}

	}

	return result;

}