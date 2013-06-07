	bool check(const vector<vector<char> > &board, int i, int j) {
		vector<int> used(9, 0);
		int n =9;
		fill(used.begin(), used.end(), 0);
		for (int j = 0; j < n; ++j) {
			if (board[i][j] == '.') continue;
			if (used[board[i][j]-'1'])
				return false;
			else
				used[board[i][j]-'1'] = true;
		}
		fill(used.begin(), used.end(), 0);
		for (int i = 0; i < n; ++i) {
			if (board[i][j] == '.') continue;
			if (used[board[i][j]-'1'])
				return false;
			else
				used[board[i][j]-'1'] = true;
		}
		fill(used.begin(), used.end(), 0);
		for (int m = 0; m < 3; ++m) {
			for (int n = 0; n < 3; ++n) {
				if (board[i/3*3+m][j/3*3+n] == '.') continue;
				if (used[board[i/3*3+m][j/3*3+n]-'1'])
					return false;
				else
					used[board[i/3*3+m][j/3*3+n]-'1'] = true;
			}
		}
		return true;
	}

    bool solveSudoku(vector<vector<char> > &board) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int rows = board.size();
		int cols = board[0].size();
		for (int i =0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if (board[i][j] != '.') continue; //BUG1
				for (int m = 1; m <=9; ++m) {
					
					board[i][j] = m +'0';
					if (check(board, i, j) && solveSudoku(board)) {
						return true;
					}
					board[i][j] = '.';                   

				}
				return false;
			}
		}
		return true; //This is the default return for i == rows
	}