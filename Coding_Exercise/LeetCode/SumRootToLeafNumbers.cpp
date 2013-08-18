    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return sumHelper(root, 0);
    }
    
    int sumHelper(TreeNode *root, int curr) {
        if (!root) return 0;
        if (!root->left && !root->right)
            return curr*10+root->val;
        
        curr = curr*10+ root->val;
        int l = sumHelper(root->left, curr);
        int r = sumHelper(root->right, curr);
        return l+r;
    }
