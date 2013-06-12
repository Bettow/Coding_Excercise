    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *dummy = new ListNode(0);
        ListNode *pre = dummy;
        dummy->next = head;
        while(head) {
            if (!head->next) 
                break;
            if (head->val == head->next->val) {
                ListNode *p = head->next;
                while (p && p->val == head->val)
                    p = p->next;
                if (p) {
                    pre->next = p;
                    head = p;
                } else {
                    pre->next = NULL;
                    head = NULL;  //dont' forget head
                }
            } else {
                pre = head;
                head = head->next;
            }
            
        }
        return dummy->next;
    }