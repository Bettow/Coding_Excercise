		bool exist(vector<vector<char> > &board, string word) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function

			int rowSize = board.size();
			int colSize = board[0].size();
			vector<vector<bool> > used(rowSize, vector<bool>(colSize,false));
			int lv = 0;
			for (int i = 0; i < rowSize; ++i) {
				for (int j = 0; j < colSize; ++j) {
					if (board[i][j] == word[0]) {
						used[i][j] = true;
						if (dfs(board, used, i, j, word, lv+1))
							return true;
						used[i][j] = false;                    
					}        
				}
			}
			return false;
		}

		bool dfs(const vector<vector<char> > &board, vector<vector<bool> > &used, 
			int x, int y, string word, int lv) {
				if (word.size() == lv) 
					return true;

				if (x-1>=0 && used[x-1][y] == false &&
					board[x-1][y] == word[lv] ) {
						used[x-1][y] = true;
						if (dfs(board, used, x-1, y, word, lv+1))
							return true;
						used[x-1][y] = false;
				}
				if (x+1<board.size() && used[x+1][y] == false &&
					board[x+1][y] == word[lv] ) {
						used[x+1][y] = true;
						if (dfs(board, used, x+1, y, word, lv+1))
							return true;
						used[x+1][y] = false;
				}
				if (y-1>=0 && used[x][y-1] == false &&
					board[x][y-1] == word[lv] ) {
						used[x][y-1] = true;
						if (dfs(board, used, x, y-1, word, lv+1))
							return true;
						used[x][y-1] = false;
				}
				if (y+1<board[0].size() && used[x][y+1] == false &&
					board[x][y+1] == word[lv] ) {
						used[x][y+1] = true;
						if (dfs(board, used, x, y+1, word, lv+1))
							return true;
						used[x][y+1] = false;
				}
				return false;
		}