    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode*> q;
        if(root) q.push(root);
        
        while(!q.empty()){
            TreeLinkNode* node = q.front();
            q.pop();
            if(node->left){
               node->left->next = node->right; 
               q.push(node->left);
            } 
            if(node->right){
                if(node->next)
                    node->right->next = node->next->left; 
                q.push(node->right);
            } 
        }
    }