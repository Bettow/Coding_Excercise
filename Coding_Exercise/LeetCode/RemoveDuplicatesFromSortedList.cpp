    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!head) return NULL;
        ListNode *pre = head;
        ListNode *curr = head->next;
        while (curr) {
            if (curr->val == pre->val) {
                pre->next = curr->next;
                delete curr;
                curr = pre->next;
            } else {
                pre = curr;
                curr = curr->next;
            }
            
        }
        return head;
    }