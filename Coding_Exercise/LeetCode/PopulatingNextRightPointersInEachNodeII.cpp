    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return;
        queue<TreeLinkNode*> st;
        st.push(root);
        queue<TreeLinkNode*> next;
        TreeLinkNode *lv = NULL;
        while (!st.empty()) {
            TreeLinkNode *node = st.front();
            st.pop();
            if (!lv) 
                lv = node->left? node->left: node->right;
            
            if (node->left) {
                next.push(node->left);
                lv->next = node->left;
                lv = lv->next;
            }
            
            if (node->right) {
                next.push(node->right);
                lv->next = node->right;
                lv = lv->next;
            }
            
            if (st.empty()) {
                st.swap(next);
                if (lv) 
                    lv->next = NULL;
                lv = NULL;
            }
            
        }
        
    }


//More concise one
void connect(TreeLinkNode *root) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	TreeLinkNode *node = root;
	while (node) {
		TreeLinkNode *nextLv = NULL;
		TreeLinkNode *prev = NULL;
		while (node) {
			if (!nextLv)
				nextLv = node->left? node->left: node->right;

			if (node->left) {
				if (prev) 
					prev->next = node->left;
				prev = node->left;
			}

			if (node->right) {
				if (prev)
					prev->next = node->right;
				prev = node->right;
			}
			node = node->next;
		}
		node = nextLv;

	}

}