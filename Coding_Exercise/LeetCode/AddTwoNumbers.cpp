	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int carry = 0;
		ListNode *head = new ListNode(0);
		ListNode *curr = head;
		while (l1 || l2) {
			if (l1) {
				//sum += l1->val + carry; //BUG multiple carry addition
				carry += l1->val;
				l1= l1->next; 			}
			if (l2) {
				carry += l2->val;
				l2= l2->next;
			}
			curr->next = new ListNode(carry%10);;  //use curr- no new node
			carry = carry/10;
			curr = curr->next;          
		}
		if (carry ==1) {  
			curr->next = new ListNode(1);
		} else {
			curr->next = NULL;
		}
		return head->next;

	}