	vector<vector<int> > ret;
	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		ret.clear();
		vector<int> path;
		pathSumHelper(root, sum, path);
		return ret;


	}

	void pathSumHelper(TreeNode *root, int sum, vector<int> path) {
		if (root == NULL)
			return;

		path.push_back(root->val);
		if (root->val == sum && !root->left && !root->right) {
			ret.push_back(path);
			return;
		}

		pathSumHelper(root->left, sum-root->val, path);
		pathSumHelper(root->right, sum-root->val, path);
	}