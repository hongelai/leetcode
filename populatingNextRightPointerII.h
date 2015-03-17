    void connect(TreeLinkNode *root) {
        if(!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        int count = 1;
        
        while(!q.empty()) {
            TreeLinkNode *tmp = q.front();
            q.pop();
            if(tmp->left) q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
            count--;

            if(count > 0){
                tmp->next = q.front();
            } else {
                tmp->next = NULL;
                count = q.size();
            }
            
        }
    }

    void connect(TreeLinkNode *root) {
        if(!root) return;
        TreeLinkNode* dummy = new TreeLinkNode(-1), *cur = root, *pre = NULL;
        
        //idea:在树的外面（左边）加一个dummyNode,pre指针，指向下一层的开始。完成一层的next添加，再通过dummy->next挪向下一层
        while(cur) {
            pre = dummy;
            pre->next = NULL;//把dummy指向上一层开始的指针断开
            while(cur) {
                if(cur->left){
                    pre->next = cur->left;
                    pre = pre->next;
                }
                if(cur->right) {
                    pre->next = cur->right;
                    pre = pre->next;
                }
                cur = cur->next;
            }
            cur = dummy->next;
        }
        
        
    }