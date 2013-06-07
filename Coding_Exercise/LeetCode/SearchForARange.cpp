vector<int> searchRange(int A[], int n, int target) {
	vector<int> ret(2, -1);
	if (n==0)
		return ret;

	int l = 0;
	int r = n;
	//should not use l<=r as a condition
	//1) A[l] would overflow as l=l+1;
	//2) when calculating mid = r+l/2 and r = mid, r is -- everytime until l = r-1; 
	while (l<r) {
		int mid = (l+r)/2;
		if (A[mid] < target) 
			l = mid+1;
		else
			r = mid;
	}
	if (A[l] != target)
		return ret;
	else
		ret[0] = l;

	r = n;
	while (l<r) {
		int mid = (l+r)/2;
		if (A[mid] > target)
			r = mid;
		else
			l = mid+1;
	}
	ret[1] = r-1;
	return ret;
}