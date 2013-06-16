public int numDistinct(String S, String T) {
	int i, j, t = T.length(), s = S.length();
	int[][] A = new int[s + 1][t + 1];
	for(i = 0; i <= s; i++) A[i][0] = 1;

	for(i = 1; i <= s; i++) {
		for(j = 1; j <= Math.min(t, i); j++) {
			if(S.charAt(i - 1) != T.charAt(j - 1)) 
				A[i][j] = A[i - 1][j];
			else 
				A[i][j] = A[i - 1][j] + A[i - 1][j - 1];
		}
	}
	return(A[s][t]);
}