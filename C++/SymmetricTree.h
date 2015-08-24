    bool isSymmetric(TreeNode *root) {
        return root ? solve(root->left, root->right) : true;
    }
    bool solve(TreeNode *left, TreeNode *right){
        if(left == NULL && right == NULL) return true;
        if(left == NULL || right == NULL) return false;
        return left->val == right->val && solve(left->left, right->right) && solve(left->right, right->left);
    }

    //
    bool isSymmetric(TreeNode *root) {
        //push into queue in pair
        if(!root) return true;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        
        while(!q.empty()) {
            TreeNode *l = q.front();
            q.pop();
            TreeNode *r = q.front();
            q.pop();
            if(l == NULL && r == NULL) continue;
            if((l == NULL && r != NULL) || (l != NULL && r == NULL) || (l->val != r->val)) return false;
            q.push(l->left);
            q.push(r->right);
            q.push(l->right);
            q.push(r->left);
        }
        return true;
    }