ListNode *reverseBetween(ListNode *head, int m, int n) {  //passed without bug
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (!head) return NULL;
	int cm = m-1;
	ListNode *dummy = new ListNode(0);
	dummy->next = head;
	ListNode *pre = dummy;
	while(cm--) {
		pre = pre->next;
	}
	int d = n-m+1;
	ListNode *t = pre->next;
	ListNode *curr = pre->next;
	ListNode *h = t;
	while (d--) {
		pre->next = curr->next;
		curr->next = h;
		h = curr;
		curr = pre->next;
	}
	t->next = pre->next;
	pre->next = h;
	return dummy->next;
}
