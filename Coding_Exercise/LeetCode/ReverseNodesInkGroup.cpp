ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head)
            return NULL;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *tail = head;
        int count = k;
        while (count && tail) {
            tail = tail->next;
            count--;
        }
        if (!tail && count)  //Here
            return head;
        ListNode *ph = dummy;
        count = k;
        while(1) {
            reverse(ph, tail);
            int count = k;
            while (tail && count) {
                tail = tail->next;
                ph = ph->next;
                count--;
            }
            if (count && !tail)  //Exit condition,  Note that tail == NULL alone is NOT an exit condition
                break;
        } 
        return dummy->next;
    }
    
void reverse(ListNode* head, ListNode* tail) {
	ListNode *p = head->next;
	ListNode *pn = tail;
	while (p != tail) {
		head->next = p->next;
		p->next = pn;
		pn = p;
		p = head->next;
	}
	head->next = pn;
}
