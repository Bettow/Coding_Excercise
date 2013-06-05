		int romanToInt(string s) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			int result =0;
			int prev = 0; //0 is ok here
			for (int i = 0; i < s.size(); ++i) {
				int curr = map(s[i]);
				result += curr;
				if (curr> prev) result -= prev*2;
				prev = curr;
			}
			return result;
		}

		int map(char c){  
			switch(c){  
			case 'I': return 1;  
			case 'V': return 5;  
			case 'X': return 10;  
			case 'L': return 50;  
			case 'C': return 100;  
			case 'D': return 500;  
			case 'M': return 1000;  
			default:  return 0;  
			}  
		} 