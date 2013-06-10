		string minWindow(string S, string T) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			int maxWindow = S.size()+1;
			unordered_map<char, int> mp;
			for (int i = 0; i < T.size(); ++i) {
				mp[T[i]]++;
			}
			unordered_map<char, int> tgt;
			int sl = 0;
			int fs = 0;
			int count = 0;
			bool found = false;
			string ret;
			for (int fs = 0; fs< S.size(); ++fs) {
				char c = S[fs];
				if (mp.find(c) == mp.end()) continue;
				if (tgt[c] < mp[c]) {
					count++;
					tgt[c]++;
				} else {
					tgt[c]++;
				}

				if (!found && T.size() == count) {
					found = true;
					ret = S.substr(0,fs+1);
				}

				if (found && T.size() == count) {
					while(sl <= fs && T.size() == count) {
						char k = S[sl];
						if (mp.find(k) != mp.end()) 
						{
							tgt[k]--;
							if (tgt[k] <mp[k]) {
								count--;
								sl++;  //don't forget sl++;
								continue;
							}
						}
						int diff = fs-sl;  //no ++ here, because sl is not increased yet!
						if (diff < ret.size())
							ret = S.substr(sl+1, diff);  //Sl+1
						sl++;
					}

				}

			}
			return ret;
		}