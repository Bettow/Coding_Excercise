int maxDepth(TreeNode *root) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (root == NULL) return 0;
	return max(maxDepth(root->left), maxDepth(root->right)) +1;

}

//Iteration Solution later