    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        if (numRows == 0)
            return ret;
            
        for (int i =0; i < numRows; ++i) {
            vector<int> row(i+1,1);
            for (int j = 1; j <i; ++j) {
                row[j] = ret[i-1][j-1] + ret[i-1][j];
            }
            ret.push_back(row);
        }
        return ret;
    }