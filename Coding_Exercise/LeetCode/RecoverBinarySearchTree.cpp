void helper(TreeNode *node, TreeNode *&prev, TreeNode *&first, TreeNode *&second) {
	if (!node)
		return;

	helper(node->left, prev, first, second);
	if (prev && prev->val > node->val) {
		if (!first) {
			first = prev;
		}
		second = node;
	
	}
	prev = node;
	helper(node->right, prev, first,second);
}

    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		TreeNode *first = NULL;
		TreeNode *second = NULL;
		TreeNode *prev = NULL;
		helper(root, prev, first, second);
		if (first && second) {
			swap(first->val, second->val);
		}
    }
