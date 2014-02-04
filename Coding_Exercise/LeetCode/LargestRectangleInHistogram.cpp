    int largestRectangleArea(vector<int> &height) {
        
        if (height.empty()) 
        {
            return 0;
        }
        stack<int> st;
        
        height.push_back(0);
        
        int ret = 0;
        for (int i = 0; i < height.size(); ++i) {
                    while (!st.empty() && height[i] < height[st.top()]) {
                        
                        int h = height[st.top()];
                        st.pop();
                        int l = st.empty()? -1:st.top();  //find previous top
                        int area = (i-l -1) * h;  //use single bar to think
                        ret = max(ret, area);
                    }
            st.push(i);
        }
        return ret;
    }
