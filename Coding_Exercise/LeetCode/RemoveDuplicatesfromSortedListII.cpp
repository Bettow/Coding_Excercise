    ListNode *deleteDuplicates(ListNode *head) {
        if (!head)
            return NULL;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
    
        ListNode *curr = dummy;
        while (curr->next && curr->next->next) {
            if (curr->next->val == curr->next->next->val) {
                ListNode *p = curr->next->next->next;
                while (p && p->val == curr->next->val) {
                    p = p->next;
                }
                curr->next = p;
            } else {
                curr = curr->next;
            }
        }
        return dummy->next;
    }
