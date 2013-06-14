    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = INT_MIN;
        int right = INT_MAX;
        return isValidHelper(root, left, right);
    }
    
    bool isValidHelper(TreeNode *root, int left, int right) {
        if (!root)
            return true;
        
        int v = root->val;
        if (v < left || v > right)
            return false;
        
        return isValidHelper(root->left, left, v-1) &&
            isValidHelper(root->right, v+1, right);
        
    }