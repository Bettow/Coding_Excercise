bool hasPathSum(TreeNode *root, int sum) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (root == NULL) return false; 
	if (root->val == sum && root->left == NULL && root->right == NULL) return true;

	return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);

}