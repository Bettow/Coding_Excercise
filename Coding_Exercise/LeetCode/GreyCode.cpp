/* Binary       Gray Code
   000       000
   001       001
   010       011
   011       010
   100       110
   101       111
   110       101
   111       100
*/

vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	vector<int> ret;
	ret.push_back(0);
	if (n==0)
		return vector<int>(1,0);
        n = 1<<(n);
	for (int i =1; i <n; i++) {
		int k = i^(i>>1);
		ret.push_back(k);
	}
        return ret;
}
