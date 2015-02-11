    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        int count = 0;
        
        while (!q.empty()) {
            TreeLinkNode *tmp = q.front();
            if (tmp->left) q.push(tmp->left);
            if (tmp->right) q.push(tmp->right);
            q.pop();
            
            if (count != 0){
                tmp->next = q.front();
                count--;
            } else {
                tmp->next = NULL;
                count = q.size() - 1;
            }
        }
    }