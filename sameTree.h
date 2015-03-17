    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        return p->val == q->val &&  isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    bool isSameTree(TreeNode *p, TreeNode *q) {
        queue<TreeNode*> Q;
        if(!p && !q) return true;
        Q.push(p);
        Q.push(q);
        while(!Q.empty()) {
            TreeNode *t1 = Q.front(); Q.pop();
            TreeNode *t2 = Q.front(); Q.pop();
            if(t1== NULL && t2 == NULL) continue;
            if(t1 == NULL || t2 == NULL) return false;
            if(t1->val != t2->val) return false;
            Q.push(t1->left);
            Q.push(t2->left);
            Q.push(t1->right);
            Q.push(t2->right);
        }
        return true;
    }