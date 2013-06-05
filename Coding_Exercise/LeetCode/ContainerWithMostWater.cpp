	int maxArea(vector<int> &height) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int result = 0;
		int st = 0;
		int ed = height.size() -1;
		while (st < ed) {
			int area = (ed -st) * min(height[st], height[ed]);
			result = max(area, result);

			if (height[st] < height[ed]) {
				st++;
			} else {
				ed--;
			}
		}
		return result;

	}