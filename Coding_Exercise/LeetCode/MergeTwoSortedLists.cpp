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