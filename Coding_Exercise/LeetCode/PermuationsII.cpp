class Solution {
public:
	vector<vector<int> > res;
	vector<vector<int> > permuteUnique(vector<int> &num) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		res.clear();
		vector<bool> used(num.size(), false);
		vector<int> rs;
		sort(num.begin(), num.end());  //dont forget sort
		dfs(0,num.size(), used, num, rs);
		return res;

	}

	void dfs(int lv, int target, vector<bool> used, vector<int> &num, vector<int> &rs) {
		if (lv == target) {
			res.push_back(rs);
			return;
		}
		int last = -1;
		for (int i =0; i < num.size(); ++i) {
			if (last >=0 && num[i] == num[last]) continue;
			if (used[i] == false) {
				used[i] = true;
				rs.push_back(num[i]);
				dfs(lv+1, target, used, num, rs);
				rs.pop_back();
				used[i] = false;
				last = i;
			}

		}
	}
};