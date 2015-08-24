    bool hasPathSum(TreeNode *root, int sum) {
        if(root == NULL) return false;
        bool hasOne = false;
        if(!root->left && !root->right) return root->val == sum ? true : false;
        if(root->left) hasOne |= hasPathSum(root->left, sum - root->val);
        if(root->right) hasOne |= hasPathSum(root->right, sum - root->val);
        return  hasOne;
    }

    //iterative
    bool hasPathSum(TreeNode *root, int sum) {
        if(root == NULL) return false;
        queue<pair<TreeNode*,int> > q;
        q.push(make_pair(root, sum - root->val));
        
        while(!q.empty()) {
            TreeNode *tmp = q.front().first;
            int leftSum = q.front().second;
            q.pop();
            if(!tmp->left && !tmp->right){
                if(leftSum == 0) return true;
                else continue;
            }
            if(tmp->left) q.push(make_pair(tmp->left, leftSum - tmp->left->val));
            if(tmp->right) q.push(make_pair(tmp->right, leftSum - tmp->right->val));
        }
        return false;
    }