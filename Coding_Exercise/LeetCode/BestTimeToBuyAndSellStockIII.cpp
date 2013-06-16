int maxProfit(vector<int> &prices) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (prices.empty()) return 0;
	vector<int> tb(prices.size(),0);
	int low = prices[0];
	int profit = 0;
	for (int i = 1; i < prices.size(); ++i) {
		if (prices[i] < low)
			low = prices[i];
		profit = max(profit, prices[i]- low);
		tb[i] = profit;
	}
	//back
	int ret = 0;
	if (prices.size() <=3) {
		for (int i =1; i< prices.size(); ++i)
			ret = max(ret, tb[i]);
		return ret;
	}

	profit = 0;
	int total_profit = 0;
	int high = prices[prices.size()-1];
	for (int i = prices.size()-2; i >0; --i) {
		high = max(high, prices[i]);
		profit = max(profit, high-prices[i]);
		total_profit = max(total_profit, profit + tb[i]);  //tb[i]
	}
	return total_profit;
}