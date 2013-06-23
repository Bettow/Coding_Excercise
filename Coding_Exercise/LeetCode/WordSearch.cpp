bool exist(vector<vector<char> > &board, string word) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function

	int m = board.size();
	int n = board[0].size();
	vector<vector<bool> > used(m, vector<bool>(n, false));
	for (int i =0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (board[i][j] == word[0]) {
				used[i][j] = true;
				if (dfs(board, word, 1, i, j, used))
					return true;
				used[i][j] = false;
			}
		}
	}
	return false;

}

bool dfs(vector<vector<char> > &board, string word, int sIndex, int x, int y, vector<vector<bool> > used) {
	if (sIndex == word.size()) {
		return true;
	}
	int m = board.size();
	int n = board[0].size();
	int dir[4][2] = {{0,-1}, {-1,0}, {0,1}, {1,0}};
	for (int i=0; i < 4; i++) {
		int nx = dir[i][0] + x;
		int ny = dir[i][1] + y;
		if (0 <=nx && nx < m && 0 <=ny && ny <n) {
			if (!used[nx][ny] && board[nx][ny] == word[sIndex]) {
				used[nx][ny] = true;
				if (dfs(board, word, sIndex+1, nx, ny, used))
					return true;
				used[nx][ny] = false;
			}
		}
	}
	return false;

}