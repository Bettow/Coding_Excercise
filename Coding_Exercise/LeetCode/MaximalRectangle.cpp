struct bar {
    int l, h;
	bar(int loc, int h) : l(loc), h(h){};
};

    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		//fill table
		int m = matrix.size();
		if (m == 0) return 0;
		int n = matrix[0].size();

		vector<vector<int> > table(m, vector<int>(n+1, 0));  //n+1
		for (int j = 0; j <n; ++j) {
			int count = 0;
			for (int i = 0; i < m ; ++i) {
				if (matrix[i][j] == '0')
					count = 0;
				else 
					count++;

				table[i][j] = count;
			}
		}

		int max_area = 0;
		for (int i = 0; i < m; i++) {
			stack<bar> sb;
			for (int j = 0; j <= n; ++j) {
				if (sb.empty() || sb.top().h <= table[i][j]) {
					sb.push(bar(j, table[i][j]));
				} else {
					while (!sb.empty() && sb.top().h > table[i][j]) {
						bar top_bar = sb.top();
						sb.pop();
						int last_loc = sb.empty()? -1: sb.top().l;
						int area = top_bar.h * (j- last_loc-1);
						max_area = max(max_area, area);
					}
                    				sb.push(bar(j, table[i][j]));  //don't forget this
				}
			}
		}
		return max_area;
    }