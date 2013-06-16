    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return helper(num,0, num.size()-1);
    }
    
    TreeNode *helper(vector<int> &num, int l, int r) {
        if (l > r) return NULL;
        int mid = l + (r-l)/2;
        TreeNode *left = helper(num, l, mid-1);
        TreeNode *node = new TreeNode(num[mid]);
        node->left = left;
        node->right = helper(num, mid+1, r);
		return node;
    }

	TreeNode *sortedListToBST(ListNode *head) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int size=0;
		ListNode *p = head;
		while (p) size++;
		return helper(head, 0, size-1);
	}

	TreeNode *helper(ListNode *head, int begin, int end) {
		if (begin > end) return NULL;
		int mid = begin + (end-begin)/2;
		TreeNode *left = helper(head, begin, mid-1);
		TreeNode *node = new TreeNode(head->val);
		head = head->next;
		TreeNode *right = helper(head, mid+1, end);
		return node;
	}