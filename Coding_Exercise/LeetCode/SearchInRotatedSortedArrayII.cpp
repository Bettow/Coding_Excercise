	bool search(int A[], int n, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		int st = 0;
		int ed = n-1;

		while (st <= ed) {
			int mid = st + (ed-st)/2;
			if (A[mid] == target)
				return true;

			if (A[st] < A[mid]) {
				if (A[st] <= target && target < A[mid])
					ed = mid-1;
				else 
					st = mid+1;
			} else if (A[mid] < A[st]) {  //cant use A[mid] > A[ed]!!!
				if (A[mid] < target && target <= A[ed])
					st = mid+1;
				else 
					ed = mid-1;
			} else {
				st++;  //B
			}
		}
		return false;
	}