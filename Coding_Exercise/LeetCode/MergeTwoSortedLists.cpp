	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;

		ListNode *result = NULL;
		if (l1->val < l2->val) {
			result = l1;
			result->next = mergeTwoLists(l1->next, l2);
		} else {
			result = l2;
			result->next = mergeTwoLists(l1, l2->next);
		}
		return result;
	}

	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (!l1) return l2;
		if (!l2) return l1;
		ListNode *dummy = new ListNode(0);
		ListNode *curr = dummy;
		while (l1 && l2) {
			if (l1->val <= l2->val) {
				curr->next = l1;
				l1 = l1->next;
			} else {
				curr->next = l2;
				l2 = l2->next;
			}
			curr = curr->next;
		}
		if (l1) curr->next = l1;
		if (l2) curr->next = l2;
		return dummy->next;
	}