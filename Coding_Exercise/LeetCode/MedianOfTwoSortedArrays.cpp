int findk(int iva[], int sa, int ivb[], int sb, int k) {

	if (sa == 0) return ivb[k-1];
	if (sb == 0) return iva[k-1];

	int i = (double)k/(sa+sb) *sa;
	int j = k-1-i;

	int ai_1 = ((i == 0) ? INT_MIN : iva[i-1]);
    	int bj_1 = ((j == 0) ? INT_MIN : ivb[j-1]);
    	int ai   = ((i == sa) ? INT_MAX : iva[i]);
    	int bj   = ((j == sb) ? INT_MAX : ivb[j]);

	if (ai_1 <=bj && bj <= ai)  //BUG: could be =
		return bj;
	if (bj_1 <= ai && ai <= bj)
		return ai;

	if (bj < ai) 
		return findk(iva, i, ivb +j +1, sb-j-1, k-j-1);
	else 
		return findk(iva+i+1, sa-i-1, ivb, j, k-i-1);		

}

double findMedianSortedArrays(int A[], int m, int B[], int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
	int sum = m+n;
	if (sum %2 !=0)
		return findk(A, m, B, n, sum/2+1);  //BUG +1
	else
		return (findk(A, m, B, n, sum/2) + findk(A, m, B, n, sum/2+1))/2.0;
        
}