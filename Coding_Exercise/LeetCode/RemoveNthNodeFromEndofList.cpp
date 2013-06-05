	ListNode *removeNthFromEnd(ListNode *head, int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (head == NULL)
			return NULL;

		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		ListNode *node = head;

		while (n--) {
			node = node->next;
		}
		ListNode *p = dummy;  //this is the previous one
		while (node) {
			p = p->next;
			node = node->next;
		}

		ListNode *toDel = p->next;
		p->next = p->next->next;
		delete toDel;
		//delete Dummy
		return dummy->next;
	}