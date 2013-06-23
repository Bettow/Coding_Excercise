int maxSubArray(int A[], int n) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int ret = INT_MIN;
	int sum = 0;
	for (int i =0; i < n; ++i) {
		sum += A[i];
		ret = max(ret, sum);  //note sequence here
		if (sum < 0)
			sum = 0;

	}
	return ret;
}