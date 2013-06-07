	int longestValidParentheses(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		int ret = 0;
		if (s.empty())
			return ret;

		stack<int> cstack;
		int length_sofar = 0;
		int left = 0;
		for (int i =0; i < s.size(); ++i) {
			if (s[i] == '(')
				cstack.push(i) ;
			else {
				if (!cstack.empty()) {
					cstack.pop();
					if (cstack.empty())
						length_sofar = i- left+1;
					else 
						length_sofar = i-cstack.top();
					ret = max(ret, length_sofar);
				} else {
					left = i +1; //reset when stack is empty(important)
				}      

			}
		}
		return ret;

	}