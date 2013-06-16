    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sum = INT_MIN;
        helper(root, sum);
        return sum;
    }
    
    int helper(TreeNode *root, int &sum) {
        if (!root)
            return 0;
            
        int leftMax = helper(root->left, sum);
        int rightMax = helper(root->right, sum);
        
        int m = root->val;
        int maxPath = max(leftMax+m, m);
        maxPath = max(maxPath, rightMax+maxPath);
        sum = max(maxPath, sum);
        
        return max(leftMax, rightMax) + m;
    }