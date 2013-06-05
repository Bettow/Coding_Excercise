	bool isValid(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		stack<char> char_s;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '(' ||
				s[i] == '[' ||
				s[i] == '{' )
				char_s.push(s[i]);
		else {
			if (s[i] == ')') {
				if (!char_s.empty() && char_s.top() == '(') {  //BUG1 should use top instead of pop.
					char_s.pop();
				} else {
					return false;
				}
			}
			if (s[i] == ']') {
				if (!char_s.empty() && char_s.top() == '[') {
					char_s.pop();
				} else {
					return false;
				}
			}
			if (s[i] == '}') {
				if (!char_s.empty() && char_s.top() == '{') {
					char_s.pop();
				} else {
					return false;
				}
			}
		}

	}
	return char_s.empty() ? true: false;

	}