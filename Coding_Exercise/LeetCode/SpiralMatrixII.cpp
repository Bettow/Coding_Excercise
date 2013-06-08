		vector<vector<int> > generateMatrix(int n) {
			vector< vector<int> > matrix(n, vector<int>(n));
			if (n == 0) return matrix;
			int beginX = 0, endX = n - 1;
			int beginY = 0, endY = n - 1;
			int num = 1;
			while (true) {
				for (int i = beginX; i <= endX; ++i)
					matrix[beginY][i] = num++;
				if (++beginY > endY) break;
				for (int i = beginY; i <= endY; ++i)
					matrix[i][endX] = num++;
				if (beginX > --endX) break;
				for (int i = endX; i >= beginX; --i)
					matrix[endY][i] = num++;
				if (beginY > --endY) break;
				for (int i = endY; i >= beginY; --i)
					matrix[i][beginX] = num++;
				if (++beginX > endX) break;
			}
			return matrix;
		}