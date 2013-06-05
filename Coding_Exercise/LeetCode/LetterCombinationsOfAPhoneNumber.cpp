	class Solution {
	public:
		vector<string> result;
		vector<string> letterCombinations(string digits) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function      
			if (digits.empty()){
				result.push_back("");
				return result;
			}

			result.clear();
			dfs(0, digits.size(), digits, "");
			return result;

		}

		void dfs(int depth, int target, string& s, string ans) {
			if (depth == target) {
				result.push_back(ans);
				return;
			}

			int c = s[depth] - '0';
			string ss = getStr(c);
			for(int i =0; i < ss.size(); ++i) {
				dfs(depth +1, target, s, ans+ss[i]);
			}
		}

		string getStr(int num) {
			switch (num) {
			case 2: return "abc";
			case 3: return "def";
			case 4: return "ghi";
			case 5: return "jkl";
			case 6: return "mno";
			case 7: return "pqrs";
			case 8: return "tuv";
			case 9: return "wxyz";
			default : return "";

			}
		}
	};