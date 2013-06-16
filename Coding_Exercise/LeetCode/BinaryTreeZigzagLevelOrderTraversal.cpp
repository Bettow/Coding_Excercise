    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        if (!root)
            return ret;
            
        stack<TreeNode *> curr, next;
        bool flag = true;
        curr.push(root);
        vector<int> lv;
        while(!curr.empty()) {
            TreeNode *node = curr.top();
            lv.push_back(node->val);
            curr.pop();
            if (flag) {
                if (node->left) next.push(node->left);
                if (node->right) next.push(node->right);
            } else {
                if (node->right) next.push(node->right);
                if (node->left) next.push(node->left);
            }
            if (curr.empty()) {
                flag = !flag;
                curr.swap(next);
                ret.push_back(lv);
                lv.clear();
            }
        
        } 
        return ret;
    }