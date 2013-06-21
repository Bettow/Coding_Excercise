    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = matrix.size();
        int n = matrix[0].size();
        if (!m || !n) 
            return false;
            
        int i = 0;
        int j = n-1;
        while (i < m && j >=0) {
            int d = matrix[i][j];
            if (d == target) {
                return true;
            } else if (target > d) {
                ++i;
            } else {
                --j;
            }
        }
        return false;
    }