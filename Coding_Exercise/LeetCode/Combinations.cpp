			class Solution {
			public:
				vector<vector<int> > result;
				vector<vector<int> > combine(int n, int k) {
					// Start typing your C/C++ solution below
					// DO NOT write int main() function
					result.clear();
					vector<int> output;
					dfs(n, 1, k, 0, output);  //starting from 1
					return result;

				}

				void dfs(int n, int st, int k, int currLv, vector<int> &output) {
					if (currLv== k) {
						result.push_back(output);
						return;
					}

					for(int i = st; i <= n; ++i) {
						output.push_back(i);
						dfs(n, st+1, k, currLv+1, output);
						//output.pop_back();
					}
				}
			};