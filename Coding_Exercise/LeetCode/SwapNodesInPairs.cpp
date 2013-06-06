	ListNode *swapPairs(ListNode *head) {
		if (!head || !head->next) return head;
		ListNode *p = head->next;
		head->next = head->next->next;
		p->next = head;
		head = p;
		head->next->next = swapPairs(head->next->next);
		return head;
	}