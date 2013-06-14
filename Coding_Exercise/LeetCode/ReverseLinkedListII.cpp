	ListNode *reverseBetween(ListNode *head, int m, int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (m >=n || head == NULL)
			return head;

		ListNode *dummy = new ListNode(0);
		ListNode *pre = dummy;
		dummy->next = head;
		ListNode *curr = head;
		int k = m-1;  //BUG1
		while(curr && k) {
			pre = curr;
			curr = curr->next;
			k--;
		}
		if (curr == NULL) return head;
		ListNode *rp = curr;
		ListNode *p = curr;
		k = n-m+1;
		while (curr && k) {
			pre->next = curr->next;
			curr->next = p;
			p= curr;
			curr = pre->next;
			k--;
		}
		pre->next = p;
		rp->next = curr;
		return dummy->next;               
	}