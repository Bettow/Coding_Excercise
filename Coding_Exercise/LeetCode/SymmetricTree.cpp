bool isSymmetric(TreeNode *root) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (root == NULL)
		return true;

	return isSym(root->left, root->right);

}
bool isSym(TreeNode *ltree, TreeNode *rtree) {
	if (!ltree && !rtree) return true;
	if (!ltree || !rtree )
		return false;

	if (ltree->val != rtree->val)
		return false;

	return isSym(ltree->left, rtree->right) && isSym(ltree->right, rtree->left);

}