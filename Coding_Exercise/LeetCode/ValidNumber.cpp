    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool is_num= false;
        bool is_dot =false;
        bool is_e =  false;
        bool is_space = false;
        while (*s && *s == ' ') s++;
        if (*s && (*s == '+' || *s == '-')) s++;
        while(*s) {
            if (*s == ' ')
                is_space = true;
            else if (is_space) {
                return false;
            } else if (isdigit(*s)) {
                is_num = true;
            } else if (*s == '.') {
                if (is_dot || is_e)
                    return false;
                is_dot = true;
            } else if (*s == 'e') {
                if (is_num && !is_e) { //&& here
                    is_e = true;
                    is_num = false;  //for case: 1e
                } else 
                    return false;
            } else if (*s == '+' || *s == '-') {
                if (*(s-1) != 'e')
                    return false;
            } else {
                return false;
            }
            s++;
        }
        return is_num;
        
    }
