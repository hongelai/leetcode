    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        queue<TreeNode*> q;
        if(root == NULL) return res;
        else q.push(root);
        int count = 1;
        while(!q.empty()){
            TreeNode* tmp = q.front();
            q.pop();
            count--;
            
            if(tmp->left) q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
            if(count == 0) {
                res.push_back(tmp->val);
                count = q.size();
            }
        }
        return res;
    }