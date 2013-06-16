TreeNode *mostRight(TreeNode *root) {
	while(root && root->right)
		root= root->right;
	return root;
}
void flatten(TreeNode *root) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (!root)
		return;

	while (root) {
		if (root->left) {
			TreeNode *node = mostRight(root->left);
			node->right = root->right;
			root->right = root->left;
			root->left = NULL;  //Don't forget
		}
		root = root->right;
	}
}