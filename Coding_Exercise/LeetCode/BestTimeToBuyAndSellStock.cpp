int maxProfit(vector<int> &prices) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (prices.size() < 2) return 0;
	int lastLow = prices[0];
	int mxProfit = 0;
	for (int i = 1; i < prices.size(); ++i) {
		int profit = prices[i] -lastLow;
		mxProfit = max(profit, mxProfit);
		if (prices[i] < lastLow)
			lastLow = prices[i];

	}        
	return mxProfit;
}