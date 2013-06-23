    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return getDepth(root, 0);
    }
    int getDepth(TreeNode *node, int depth) {
        if (node == NULL)
            return depth;
        if (!node->left && !node->right)
            return depth+1;
        
        
        int leftDepth = node->left? getDepth(node->left, depth+1):INT_MAX;
        int rightDepth = node->right? getDepth(node->right, depth+1):INT_MAX;
        return min(leftDepth, rightDepth);
        
    }