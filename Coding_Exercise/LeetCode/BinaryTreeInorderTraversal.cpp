    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        if (!root) 
            return ret;
        
        TreeNode *curr = root;
        stack<TreeNode*> st;
        bool done = false;
        while (!done) {
            if (curr) {
                st.push(curr);
                curr = curr->left;
            } else {
                if (st.empty())
                    done = true;
                else {
                    curr = st.top(); //BUG
                    st.pop();
                    ret.push_back(curr->val);
                    curr= curr->right; 
                }
            }
        }
        return ret;
        
    }