string multiply(string num1, string num2) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int s1 = num1.size();
	int s2 = num2.size();
	if (!s1 || !s2) return string();

    	vector<int> iv(s1+s2,0);
	for (int i =0; i < s1; i++) 
		for (int j = 0; j < s2; j++) 
			iv[s1+s2-2-i-j] += (num1[i]-'0')*(num2[j]-'0');

	int carry = 0;
	for (int i = 0; i < iv.size(); ++i) {
		int sum = iv[i]+ carry;
		iv[i] = sum%10;
		carry = sum/10;
	}

	//remove zeroes
	int n = s1+s2-1;
	while (n>=1 && iv[n--] ==0)
		iv.pop_back();

	string ret;
	for (int i = iv.size()-1; i >=0; --i)
		ret.push_back(iv[i]+'0');
	return ret;

}