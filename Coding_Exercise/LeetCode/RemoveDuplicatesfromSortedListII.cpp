    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *curr = dummy;
        while (curr) {
            if (curr->next && curr->next->next) {
                if (curr->next->val == curr->next->next->val) {
                    ListNode *p = curr->next->next;
                    while (p && curr->next->val == p->val) {
                        p = p->next;    
                    }
                    curr->next = p;
                } else {
                    curr = curr->next;
                }
            } else {
                break;
            }
        }
        return dummy->next;
    }
