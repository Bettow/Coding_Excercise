	vector<string> anagrams(vector<string> &strs) {
		
		vector<string> ret;
		map<string, vector<string> > m;  //This
		ret.clear();
		m.clear();
		for(int i = 0; i < strs.size(); i++){
			string sortStr(strs[i]);
			sort(sortStr.begin(), sortStr.end());

			m[sortStr].push_back(strs[i]);
		}

		for(map<string, vector<string> >::iterator iter = m.begin(); iter != m.end(); iter++){
			if ((iter->second).size() > 1)
				for(int i = 0; i < (iter->second).size(); i++)
					ret.push_back((iter->second)[i]);
		}

		return ret;
	}
