int maxProfit(vector<int> &prices) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (prices.size() < 2) return 0;
	int lastLow = prices[0];
	int sum =0;
	for (int i = 0; i < prices.size(); ++i) {
		sum += max(0, prices[i]- lastLow);
		lastLow = prices[i];
	}
	return sum;

}