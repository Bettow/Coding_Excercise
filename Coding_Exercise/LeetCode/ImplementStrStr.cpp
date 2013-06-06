	char *strStr(char *haystack, char *needle) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (*needle == '\0')
			return haystack;

		while (*haystack) {
			char *curr = haystack;
			char *n = needle;  //BUG3 reset needle;
			while (*curr && *n && *curr == *n) { 
				curr++;
				n++;
			}
			if (*n == '\0')  //BUG2 only test needle
				return haystack;          
			haystack++;

		}
		return NULL;
	}