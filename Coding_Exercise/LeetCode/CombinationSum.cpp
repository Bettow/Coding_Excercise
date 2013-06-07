	class Solution {
	public:
		vector<vector<int> > result;
		vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function

			result.clear();
			vector<int> output;
			sort(candidates.begin(), candidates.end());
			dfs(candidates, output,0, 0,target);  //BUG: p is used to avoid (1,2) and (2,1) redundant
			return result;

		}
		void dfs(vector<int> &candidates, vector<int> output, int p, int curr_sum, int target) {            
			for (int i =p; i < candidates.size(); ++i) {
				int sum = candidates.at(i) + curr_sum;
				if ( sum == target) {
					output.push_back(candidates[i]);
					result.push_back(output);
					return;
				} else if (sum > target) {
					return;
				} else {
					output.push_back(candidates[i]);
					dfs(candidates, output,i, sum,  target);
					sum = sum - candidates.at(i); 
					output.pop_back();
				}
			}
			return;        
		} 
	};