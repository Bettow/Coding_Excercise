	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		if (!m || !n)
			return 0;        

		vector<vector<int> > tb(m, vector<int>(n,0));
		if (obstacleGrid[0][0]==1)
			return 0;
		else
			tb[0][0] = 1;  //should set this

		for (int i =1; i <n ; ++i) {
			if (obstacleGrid[0][i] ==1 ||
				tb[0][i-1] == 0)
				tb[0][i]=0;
			else
				tb[0][i]=1;

		}
		for (int i =1; i <m ; ++i) {
			if (obstacleGrid[i][0] ==1 ||
				tb[i-1][0] == 0)
				tb[i][0]=0;
			else
				tb[i][0]=1;                
		}

		for (int i = 1; i <m; ++i) {
			for (int j =1 ; j < n; ++j) {
				if (obstacleGrid[i][j]==1)
					tb[i][j]=0;
				else
					tb[i][j] = tb[i-1][j]+ tb[i][j-1];      

			}
		}
		return tb[m-1][n-1];

	}