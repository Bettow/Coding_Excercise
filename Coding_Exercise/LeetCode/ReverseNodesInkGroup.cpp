	//need to improve
	ListNode *reverseKGroup(ListNode *head, int k) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (k <=1) return head;

		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		ListNode *pre = dummy;
		int i = 1;
		while (head) {
			if (i %k ==0) {
				pre = rg(pre, head->next);
				head = pre->next;                
			} else {
				head = head->next;                
			}
			i++;
		}
		return dummy->next;
	}

	ListNode *rg(ListNode *pre, ListNode *tail_next) {
		ListNode *last = pre->next;
		ListNode *curr = last->next;
		ListNode *lh = last;
		while (curr != tail_next) {
			ListNode *p = curr->next;
			curr->next = lh;
			lh = curr;
			curr = p;
		}

		pre->next =lh;
		last->next= tail_next;
		return last;

	}