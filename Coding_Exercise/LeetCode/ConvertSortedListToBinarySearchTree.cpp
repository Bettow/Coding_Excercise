TreeNode *sortedListToBST(ListNode *head) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function

	ListNode *p = head;
	int n =0;
	while(p) {
		p= p->next;
		n++;
	}

	return helper(head, 0, n-1);
}

TreeNode *helper(ListNode *&head, int st, int ed) { //important to return &head, otherwise, left node won't increase
	if (st > ed)
		return NULL;

	int mid = (st+ed)/2;
	TreeNode *leftNode = helper(head, st, mid-1);  // <-- head is increased here
	TreeNode *node = new TreeNode(head->val);
	node->left = leftNode;
	head = head->next;
	node->right = helper(head, mid+1, ed);
	return node;    

}