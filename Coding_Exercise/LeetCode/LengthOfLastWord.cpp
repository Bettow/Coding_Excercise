    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ret =0;
        int count = 0;
        while (*s) {
            if (isalpha(*s)) {
                count++;
                ret = count;
            } else {
                count=0;
            }
            s++;
        }
        return ret;
    }