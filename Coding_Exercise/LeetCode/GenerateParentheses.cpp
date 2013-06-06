	class Solution {
	public:
		vector<string> result;
		vector<string> generateParenthesis(int n) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			result.clear();
			string out;
			dfs(0,0, n, out);
			return result;

		}

		void dfs(int l, int r, int n,  string output) {
			if (l ==n && r==n) {
				result.push_back(output);
				return;
			}
			if (r>l) return;
			if (l < n) {
				//cant' use output = output +')'  it will be reused/rollback
				
				dfs(l+1, r, n, output + '(');
			}
			if (r < l) {
				dfs(l, r+1, n, output + ')');
			}
		}

	};