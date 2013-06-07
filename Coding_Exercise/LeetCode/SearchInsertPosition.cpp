	int searchInsert(int A[], int n, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int st = 0;
		int ed = n-1;
		if (target <= A[0])
			return 0;
		if (target > A[n-1])
			return n;

		while (st < ed) {
			int mid = st+(ed-st)/2;
			if (A[mid] == target) {
				return mid;
			} else if (A[mid] > target) {
				ed = mid-1; 
			} else {
				st = mid+1;
			}
		}
		return A[st] >= target? st: st+1;  //BUG
	}