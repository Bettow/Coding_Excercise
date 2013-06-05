	int threeSumClosest(vector<int> &num, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		sort(num.begin(), num.end());
		int ret = num[0]+num[1]+num.back();
		int min_r = abs(target-ret);
		for (int i = 0; i < num.size()-2; ++i) {
			int l = i+1;
			int r = num.size()-1;

			while (l < r) {
				int sum = num[i]+num[l]+num[r];
				int diff = abs(target-sum);
				if (diff < min_r) {
					min_r = diff;
					ret = sum;  //BUG1 should return sum;
				}

				if (min_r == 0)
					return sum;

				if (sum > target) {
					r--;
				} else {
					l++;
				}

			}
		}
		return ret;

	}