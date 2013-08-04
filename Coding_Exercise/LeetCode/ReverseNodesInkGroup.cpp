ListNode *reverseKGroup(ListNode *head, int k) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (!head) return NULL;
	int c = k;
	ListNode *dummy = new ListNode(0);
	dummy->next = head;
	ListNode *pre = dummy;
	ListNode *t = pre;
	while (t && c) {
		t= t->next;
		c--;
		if (!t)
			break;
		if (c==0) {
			pre = revsersK(pre, t->next);  //pre will be changed
			t = pre;
			c = k;
		}
	}
	return dummy->next;

}
ListNode* revsersK(ListNode *pre, ListNode *tail) {
	ListNode *curr = pre->next;
	ListNode *h = tail;
	ListNode *ret = curr;
	while (curr != tail) {
		ListNode *n = curr->next;
		curr->next = h;
		h = curr;
		curr = n;
	}
	pre->next = h;
	return ret;
}