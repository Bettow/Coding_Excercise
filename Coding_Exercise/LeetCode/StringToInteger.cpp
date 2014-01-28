int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        while (*str != '\0' && *str == ' ') {
            str++;
        }
        if (*str == '\0')
            return 0;
            
        bool isNeg = false;
        if (*str == '-') {
            isNeg = true;
            str++;
        }
        
        if (*str == '+')  //BUG1
            str++;
        
        //first valid digit
        int result = 0;
        while(*str != '\0') {
            if (*str >='0' && *str <='9') {
                int d = *str-'0';
                if (INT_MAX/10 >= result) {  //This is for "-2147483647"	-2147483648	-2147483647?
                    result = result*10;
                } else {
                    return isNeg? INT_MIN: INT_MAX;
                }
                
		//because INT_MAX < abs(INT_MIN) ...48
		//when the input is -2147483648 the 2147483648 is an overflow of max int, 
		//will return the min int -2...8
                if (INT_MAX- d >= result) {  //must use >= not <=
                    result = result+d;
                } else {
                    return isNeg? INT_MIN: INT_MAX;
                }
                str++;
            }  else {  //BUG2 increase for non-digit
                break;  
            }
        }
        return isNeg? -result:result;
 }
 
 //new version

	int atoi(const char *str) {
		if (str == NULL)
			return 0;
		while (*str == ' ')
			str++;
		bool is_negative = false;
		if (*str == '+') {
			str++;
		}
		else if (*str == '-') {
			is_negative = true;
			str++;
		}

		long long ret = 0;
		while (*str) {
			char c = *str;
			if (!isdigit(c))
				break;
			int n = c - '0';
			ret = ret * 10 + n;
			if (!is_negative) {
			    if (ret >= INT_MAX) {
			        return INT_MAX;
			    }
			} else {
			    if (-ret <= INT_MIN) {
			        return INT_MIN;
			    }
			}
			str++;
		}
		return is_negative? -ret: ret;
	}
