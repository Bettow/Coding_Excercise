    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_map<char, char> bmap;
        stack<char> stack_c;
        bmap['('] = ')';
        bmap['['] = ']';
        bmap['{'] = '}';
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (bmap.count(c)) {
                stack_c.push(c);
            } else {
                if (stack_c.empty() || bmap[stack_c.top()] != c){
                    return false;
                } else {
                    stack_c.pop();
                }
            }
        }
        return stack_c.empty()? true: false;
    }
