    vector<int> ret;
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        ret.clear();
        if (matrix.empty())
            return ret;
            
        helper(matrix, 0, matrix[0].size()-1, 0, matrix.size()-1);
        return ret;
        
    }
    
    void helper(vector<vector<int> > &matrix, int left, int right,int top, int bot) {
        if (left> right || bot < top)
            return ;
        
        if (top == bot) {
            for (int i = left; i <= right; ++i) 
                ret.push_back(matrix[top][i]);
            return;
        }
        if (left == right) {
            for (int i = top; i <= bot; ++i)
                ret.push_back(matrix[i][left]);
            return;
        }
        
        for (int i = left; i <=right; ++i) {
            ret.push_back(matrix[top][i]);
        }
        
        for (int i = top+1; i<= bot; ++i)
            ret.push_back(matrix[i][right]);
            
        for (int i = right-1; i>=left; --i)
            ret.push_back(matrix[bot][i]);
        
        for (int i = bot-1; i>= top+1; --i)
            ret.push_back(matrix[i][left]);
        
        helper(matrix, left+1, right-1, top+1, bot-1);
    }