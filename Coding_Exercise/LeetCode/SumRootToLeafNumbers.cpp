    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sum = 0, curr= 0;
        helper(root, sum, curr);
        return sum;
        
    }
    
    void helper(TreeNode *root, int &sum, int curr) {
        if (!root)
            return;
        
        curr = curr*10+root->val;
        if (!root->left && !root->right) {
            sum += curr;
            return;
        }
        
        
        helper(root->left, sum, curr);
        helper(root->right, sum, curr);
        
    }