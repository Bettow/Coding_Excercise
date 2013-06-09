	int minPathSum(vector<vector<int> > &grid) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int rowSize = grid.size();
		if(rowSize == 0) return 0;
		int colSize = grid[0].size();
		if (colSize == 0) return 0;
		vector<vector<int> > table(rowSize, vector<int>(colSize, 0));   //remember!
		int sum = 0;
		for (int i = 0; i < rowSize; ++i) {
			sum += grid[i][0];
			table[i][0] = sum;
		}
		sum = 0;
		for (int i = 0; i < colSize; ++i) {
			sum += grid[0][i];
			table[0][i] = sum;
		}
		for (int i = 1; i < rowSize; ++i) {
			for (int j = 1; j < colSize; ++j) {
				table[i][j] = min(table[i-1][j], table[i][j-1]) + grid[i][j];
			}
		}
		return table[rowSize-1][colSize-1];        
	}