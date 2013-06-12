	struct bar {
		int height;
		int loc;
		bar(int h, int l): height(h), loc(l){}
	};

	//optimize later to remove duplicated code
	int largestRectangleArea(vector<int> &height) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (height.empty())
			return 0;

		stack<bar> sb;
		int marea =0;
		for(int i = 0; i < height.size(); ++i) {
			if (sb.empty()) {
				sb.push(bar(height[i],i+1));
			} else {
				if (sb.top().height < height[i]) {
					sb.push(bar(height[i],i+1));
				} else {
					while (!sb.empty() && sb.top().height > height[i]) {
						bar b = sb.top();
						sb.pop();
						int last_loc = sb.empty()? 0: sb.top().loc;
						int dist = i - last_loc; //note here
						int area = dist * b.height;
						marea = max(marea, area);                    
					}    
					sb.push(bar(height[i],i+1));
				}

			}
		}
		while (!sb.empty()) {
			bar b = sb.top();
			sb.pop();
			int last_loc = sb.empty()? 0: sb.top().loc;
			int dist = height.size() - last_loc;
			int area = dist * b.height;
			marea = max(marea, area);
		}
		return marea;
	}