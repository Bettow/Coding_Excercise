bool isBalanced(TreeNode *root) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (!root)
		return true;

	if (abs(getHeight(root->left) - getHeight(root->right))>1)
		return false;

	return isBalanced(root->left) && isBalanced(root->right);

}
int getHeight(TreeNode *root){
	if (!root)
		return 0;
	return max(getHeight(root->left), getHeight(root->right))+1;
}