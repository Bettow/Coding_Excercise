	ListNode *swapPairs(ListNode *head) {
		if (!head || !head->next) return head;
		ListNode *p = head->next;
		head->next = head->next->next;
		p->next = head;
		head = p;
		head->next->next = swapPairs(head->next->next);
		return head;
	}
	
	//iterative
	ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!head)
            return NULL;
        if (!head->next)
            return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *curr = dummy;
        while (curr->next && curr->next->next) {
            ListNode *t = curr->next;
            curr->next = t->next;
            t->next = t->next->next;
            curr->next->next = t;
            curr = curr->next->next;
        }
        return dummy->next;
    }
