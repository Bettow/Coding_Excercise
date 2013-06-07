	//32. Search in Rotated Sorted Array
	int search(int A[], int n, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (n ==0) return -1;

		int left =0, right = n-1;
		while (left<= right) {
			int mid = (left+right)/2;
			if (A[mid] == target)
				return mid;

			if (A[left] <= A[mid]) {
				if (A[left] <= target && target < A[mid]) {  //BUG <=  
					right = mid -1;
				} else {
					left = mid +1;
				}

			} else {
				if (A[mid] < target && target <= A[right]) {
					left = mid+1;
				} else 
					right = mid -1;

			}
		}
		return -1;
	}