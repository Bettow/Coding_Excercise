    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
            
        for (int i = 0; i <=rowIndex; ++i) {
            ret.push_back(1);
            for (int j = i-1; j >0 ; --j) {
                ret[j] = ret[j] + ret[j-1];
            }
        }
        return ret;
    }