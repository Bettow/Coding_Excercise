	ListNode *mergeKLists(vector<ListNode *> &lists) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (lists.empty()) return NULL;

		vector<ListNode*> hp;
		for (int i =0; i < lists.size(); ++i) {
			if (lists[i]) {  //test NULL of list
				hp.push_back(lists[i]);
			}
		}

		if (hp.empty()) return NULL;

		make_heap(hp.begin(), hp.end(), comp());
		ListNode *dummy = new ListNode(0);
		ListNode *node = dummy;
		while(!hp.empty()) {
			ListNode *v = hp.front(); 
			pop_heap(hp.begin(), hp.end(), comp()); 
			hp.pop_back();
			node->next = new ListNode(v->val);
			v= v->next;
			node =  node->next;
			if (v) {
				hp.push_back(v);
				push_heap(hp.begin(), hp.end(), comp());
			}
		}
		return dummy->next;
	}

	class comp {
	public:
		bool operator()(ListNode *l1, ListNode* l2) const {
			return l1->val > l2->val;
		}
	};
