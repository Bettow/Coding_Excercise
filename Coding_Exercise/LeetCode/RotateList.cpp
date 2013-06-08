	ListNode *rotateRight(ListNode *head, int k) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (head == NULL) return NULL;
		if (k ==0) return head;
		ListNode *p = head;
		int count =1;
		while(p->next) {
			count++;
			p=p->next;
		}
		if (count == 1) return head;
		p->next = head;
		int n = count-k%count;  //BUG
		while (n--) {  //think
			p=p->next;
		}
		head = p->next;
		p->next = NULL;
		return head;
	}