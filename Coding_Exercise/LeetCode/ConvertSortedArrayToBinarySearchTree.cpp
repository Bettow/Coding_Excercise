    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return helper(num,0, num.size()-1);
    }
    
    TreeNode *helper(vector<int> &num, int l, int r) {
        if (l > r) return NULL;
        int mid = l + (r-l)/2;
        TreeNode *left = helper(num, l, mid-1);
        TreeNode *node = new TreeNode(num[mid]);
        node->left = left;
        node->right = helper(num, mid+1, r);
		return node;
    }


//Iterative
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = num.size();
        if (m==0)
            return NULL;
        TreeNode *root = BuildBst(m);
        TreeNode *curr= root;
        stack<TreeNode*> st;
        bool done = false;
        int i = 0;
        while(!done) {
            if (curr) {
                st.push(curr);
                curr = curr->left;
            } else {        
                if (st.empty()) {
                    done = true;
                } else {
                    curr = st.top();
                    st.pop();
                    curr->val = num[i++];
                    curr = curr->right;                
                }
            }
        }
        return root;
    }
    
    TreeNode *BuildBst(int n) {
        vector<TreeNode*> vt;
        for (int i =0; i < n; ++i)
            vt.push_back(new TreeNode(0));
            
        for (int i =0; i < n; ++i) {
            if (i*2+1 < n)
                vt[i]->left = vt[i*2+1];
            if (i*2+2 < n)
                vt[i]->right = vt[i*2+2];
        }
        return vt[0];
    }