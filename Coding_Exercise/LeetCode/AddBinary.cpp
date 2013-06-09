		string addBinary(string a, string b) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			int ia = a.size()-1;
			int ib = b.size()-1;

			string result;
			int carry = 0;
			while (ia>=0 || ib>=0) {  //BUG use >=0
				if (ia>=0) {
					carry += a[ia]-'0';
					--ia;
				}
				if (ib>=0) {
					carry += b[ib]-'0';
					--ib;
				}

				int digit = carry%2;
				char c = digit + '0';
				result = c + result; //note!
				carry /= 2;
			}
			if (carry)
				result = string("1") + result;
			return result;
		}