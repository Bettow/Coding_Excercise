vector<vector<int> > levelOrder(TreeNode *root) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<vector<int> > ret;
	if (root== NULL)
		return ret;

	queue<TreeNode *> qt;
	queue<TreeNode *> nxt;
	qt.push(root);
	vector<int> lv;
	while (!qt.empty()) {
		TreeNode *node = qt.front();
		qt.pop();
		lv.push_back(node->val);
		if (node->left)
			nxt.push(node->left);
		if (node->right)
			nxt.push(node->right);

		if (qt.empty()){
			qt.swap(nxt);
			ret.push_back(lv);
			lv.clear();
		}
	}
	return ret;

}