		string intToRoman(int num) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function    
			string result;
			result += roman(num/1000, 'M', ' ', ' ');
			result += roman(num/100%10, 'C', 'D', 'M');
			result += roman(num/10%10, 'X', 'L' ,'C');
			result += roman(num%10, 'I', 'V', 'X');
			return result;

		}

		string roman(int num, char one, char five, char ten) {
			string result;
			if (num ==9) {
				result += one;
				result += ten;
			} else if (num >= 5) {
				result += five;
				while(num-- >5)
					result += one;
			} else if (num == 4) {
				result += one;
				result += five;
			} else {
				while (num-- >0)
					result += one;
			}
			return result;
		}