	vector<vector<int> > fourSum(vector<int> &num, int target) {
		vector<vector<int> > ret;
		if(num.size() < 4) return ret;
		sort(num.begin(), num.end());
		for(int i = 0; i < num.size(); ++i)
			for(int j = i + 1; j < num.size(); ++j) {
				int left = j + 1;
				int right = (int)num.size() - 1;
				int sum = 0;
				while(left < right){
					sum=num[i]+num[j]+num[left]+num[right];
					if(target == sum){
						ret.push_back(vector<int>(4));
						ret.back()[0]=num[i];
						ret.back()[1]=num[j];
						ret.back()[2]=num[left];
						ret.back()[3]=num[right];
						++left;
						--right;
					}
					else if(sum > target)
						--right;
					else
						++left;
				}
			}

		sort(ret.begin(), ret.end());
		ret.resize(unique(ret.begin(),ret.end())-ret.begin());
		return ret;
	}