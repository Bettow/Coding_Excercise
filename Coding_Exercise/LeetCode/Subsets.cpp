		vector<vector<int> > subsets(vector<int> &S) {     
			vector<int> path;
			vector<vector<int> > result;

			sort(S.begin(), S.end());
			sub(S, 0, path, result);
			return result;
		}

		void sub(vector<int> &s, int begin, vector<int> &path, 
			vector<vector<int> > &result) {
				result.push_back(path);  //key

				for (int i = begin; i < s.size(); ++i) {
					//if (i != begin && s[i] == s[i - 1]) continue;

					path.push_back(s[i]);
					sub(s, i + 1, path, result);  //BUG i+1
					path.pop_back();
				}
		}