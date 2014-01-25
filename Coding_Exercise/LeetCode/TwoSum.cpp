    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_map<int, int> im;
        for (int i =0; i< numbers.size(); ++i) {
            im[numbers[i]] = i;
        }
        vector<int> r(2);
        for (int i = 0; i < numbers.size(); ++i) {
            int s = target - numbers[i];
            if (im.count(s) && i != mp[s]) {
                r[0] = i+1;
                r[1] = im[s]+1;
                return r;
            }
        }
    }
