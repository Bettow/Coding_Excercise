    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_set<int> si;
        for (int i = 0; i < num.size(); ++i) {
            si.insert(num[i]);    
        }
        int ret = 0;
        for (unordered_set<int>::iterator iter = si.begin(); iter != si.end(); ++iter) {
            int l = getLength(si, *iter, false) + getLength(si, *iter+1, true);
            ret = max(ret,l);
        }
        return ret;
    }
    
    int getLength(unordered_set<int> si, int e, bool dir) {
        int count = 0;
        while (si.find(e) != si.end()) {
            count++;
            si.erase(si.find(e));  //key 
            if (dir) 
                e++;
            else
                e--;
        }
        return count;
    }
