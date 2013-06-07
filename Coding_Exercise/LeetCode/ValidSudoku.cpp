	bool isValidSudoku(const vector<vector<char> > &board) {
		vector<int> used(9, 0);
		int n =9;
		for (int i = 0; i < n; ++i) {
			fill(used.begin(), used.end(), 0);
			for (int j = 0; j < n; ++j) {
				if (board[i][j] == '.') continue;
				if (used[board[i][j]-'1'])
					return false;
				else
					used[board[i][j]-'1'] = true;
			}
		}
		for (int i = 0; i < n; ++i) {
			fill(used.begin(), used.end(), 0);
			for (int j = 0; j < n; ++j) {
				if (board[j][i] == '.') continue;
				if (used[board[j][i]-'1'])
					return false;
				else
					used[board[j][i]-'1'] = true;
			}
		}
		for (int i = 0; i < n; i = i+3 ) {
			for (int j = 0; j < n; j = j+3) {
				fill(used.begin(), used.end(), 0);
				for (int m = 0; m < 3; ++m) {
					for (int n = 0; n < 3; ++n) {
						if (board[i+m][j+n] == '.') continue;
						if (used[board[i+m][j+n]-'1'])
							return false;
						else
							used[board[i+m][j+n]-'1'] = true;
					}
				}              
			}
		}
		return true;
	}