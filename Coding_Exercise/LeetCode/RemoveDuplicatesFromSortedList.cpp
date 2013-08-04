ListNode *deleteDuplicates(ListNode *head) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	ListNode *pre = head;
	while (pre) {
		if (pre->next && pre->val == pre->next->val) {
			ListNode *n = pre->next;
			pre->next = n->next;
			delete n;
		} else {
			pre = pre->next;
		}
	}
	return head;
}