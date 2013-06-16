	void dfs(char marker, int r, int c, vector<vector<char> > &board)
	{
		board[r][c] = marker;
		queue<pair<int, int> > q;
		int n = board.size(), m = board[0].size();

		q.push(make_pair(r, c));

		int d[4][2] = {{0, -1}, {-1,0}, {0,1}, {1, 0}};
		while (!q.empty()) {
			pair<int, int> p = q.front(); 
			q.pop();
			int x = p.first;
			int y = p.second;
			for (int i =0; i <4; i++) {
				int xn = x+d[i][0];
				int yn = y+d[i][1];
				if (xn>=0 && xn< n && yn >=0 && yn <m &&
					board[xn][yn] == 'O')
				{
					q.push(make_pair(xn, yn));
					board[xn][yn] = marker;
				}
			}
		}

	}

	void solve(vector<vector<char>> &board) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (board.empty()) return;
		// start from border, mark all O, then set all other O to X
		int n = board.size(), m = board[0].size();
		const char marker = 'T';
		for (int j=0; j<m; ++j) {
			int i;
			i = 0; if (board[i][j] == 'O') dfs(marker, i, j, board);
			i = n-1; if (board[i][j] == 'O') dfs(marker, i, j, board);
		}
		for (int i=0; i<n; ++i) {
			int j;
			j = 0; if (board[i][j] == 'O') dfs(marker, i, j, board);
			j = m-1; if (board[i][j] == 'O') dfs(marker, i, j, board);
		}
		for (int i=0; i<n; ++i)
			for (int j=0; j<m; ++j)
				if (board[i][j] == marker) board[i][j] = 'O';
				else if (board[i][j] == 'O') board[i][j] = 'X';
	}