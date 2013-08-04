    int getDepth(TreeNode *root, int lv) {
        if (!root) 
            return lv-1;
        
        int l = getDepth(root->left, lv+1);
        int r = getDepth(root->right, lv+1);
        
        if (l == lv && r == lv)
            return lv;
        else if (l == lv)
            return r;
        else if (r == lv)
            return l;
        else 
            return min(r, l);
        
        
    }
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return getDepth(root, 1);
    }
