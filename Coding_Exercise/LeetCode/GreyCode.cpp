		vector<int> grayCode(int n) {
			vector<int> ret;
			int count = 1 << n;
			for(int i = 0 ; i < count; ++i) {
				ret.push_back(i ^ (i>>1));
			}
			return ret;
		}