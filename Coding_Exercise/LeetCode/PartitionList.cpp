    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        ListNode *left = new ListNode(0);
        ListNode *pl = left;
        ListNode *right = new ListNode(0);
        ListNode *pr = right;
        while (head) {
            if (head->val < x) {
                pl->next = head;
                pl = pl->next;
            } else {
                pr->next = head;
                pr = pr->next;
            }   
            head = head->next;
        }
        pl->next = right->next;
        pr->next = NULL;
        return left->next;
        //delete dummy nodes
    }