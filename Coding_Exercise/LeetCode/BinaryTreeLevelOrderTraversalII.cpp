vector<vector<int> > levelOrderBottom(TreeNode *root) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<vector<int> > ret;
	if (root == NULL) 
		return ret;

	queue<TreeNode*> q;
	q.push(root);
	int curr_lv =1;
	int next_lv =0;
	vector<int> lv;
	while (!q.empty() ) {
		TreeNode *node = q.front();
		q.pop();
		lv.push_back(node->val);
		curr_lv--;
		if (node->left) {
			q.push(node->left);
			next_lv++;
		}
		if (node->right) {
			q.push(node->right);
			next_lv++;
		}
		if (curr_lv ==0) {
			curr_lv = next_lv;
			next_lv = 0;
			ret.push_back(lv);
			lv.clear();
		}

	}

	vector<vector<int> > r;
	for (int i = ret.size()-1; i>=0; --i) {
		r.push_back(ret.at(i));
	}
	return r;

}