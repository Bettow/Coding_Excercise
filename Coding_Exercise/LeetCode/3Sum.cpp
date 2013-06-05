	vector<vector<int> > threeSum(vector<int> &num) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function


		vector<vector<int> > ret;
		if (num.size() <=2)
			return ret;

		sort(num.begin(), num.end());
		for (int i =0; i < num.size()-2; ++i) {
			if(i > 0 && num[i]==num[i-1]) continue;

			int l = i+1;
			int r = num.size()-1;
			while (l < r) {
				if (l-1> i && num[l]== num[l-1]) {  //BUG2
					l++;
					continue;
				}

				if (r+1 < num.size() && num[r] == num[r+1]) {
					r--;
					continue;
				}
				int sum = num[l] + num[r] + num[i];
				if (sum < 0) {
					l++;
				} else if (sum > 0) {
					r--;
				} else {
					vector<int> iv(3);
					iv[0] = num[i];  //BUG1
					iv[1] = num[l];
					iv[2] = num[r];
					ret.push_back(iv);
					l++;  //BUG2
				}
			}

		}
		return ret;

	}