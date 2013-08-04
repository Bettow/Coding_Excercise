	struct bar {
		int height;
		int loc;
		bar(int h, int l): height(h), loc(l){}
	};

    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (height.empty())
            return 0;
        stack<bar> sb;
        int max_area = 0;
        int n = height.size();
        height.push_back(0);
        for (int i =0; i <=n; ++i) {
            if (!sb.empty() && sb.top().height > height[i]) {  //> or >== are the same
                while (!sb.empty() && sb.top().height > height[i]) {
                    bar b = sb.top();
                    sb.pop();
                    int l = sb.empty()? -1: sb.top().loc;
                    int area = (i - l-1) * b.height; //i-l-1  //l is after pop need to -1
                    max_area = max(max_area, area);
                }                    
            }
            sb.push(bar(height[i], i));  //need to push in all cases
        }
        return max_area;
    }
