    class comp {
        public:
        bool operator()(ListNode *l, ListNode *r) {
            return l->val > r->val;   //Return larger for head and priority queue
        }
    };
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (lists.empty())
            return NULL;
        
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i])
                pq.push(lists[i]);
        }
        ListNode *dummy_head = new ListNode(0);
        ListNode *curr = dummy_head;
        while(!pq.empty()){
            ListNode *n = pq.top();
            pq.pop();
            curr->next = n;
            if (n->next)
                pq.push(n->next);
            curr = curr->next;
        }
        return dummy_head->next;
    }
