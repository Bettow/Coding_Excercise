    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root)
            return;
            
        if (root->left)
            root->left->next = root->right;
        if (root->right) 
            root->right->next = root->next? root->next->left: NULL;
            
        connect(root->left);
        connect(root->right);       
    }