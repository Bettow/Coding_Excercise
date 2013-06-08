void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        helper(matrix, 0);       
        
}
    
    void helper(vector<vector<int> > &matrix, int offset) {
        int n = matrix.size();
        if (offset*2 >=n-1)
            return;
        
        for (int i = offset; i< n-offset-1; i++) {
            int tmp = matrix[offset][i];
            matrix[offset][i] = matrix[n-i-1][offset];
            matrix[n-i-1][offset] = matrix[n-offset-1][n-i-1];
            matrix[n-offset-1][n-i-1] = matrix[i][n-offset-1];
            matrix[i][n-offset-1] = tmp;       
        }
        
        helper(matrix, offset+1);       
            
    }