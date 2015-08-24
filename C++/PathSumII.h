    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > res;
        vector<int> entry;
        
        dfs(root,sum,entry,res);
        return res;
    }
    void dfs(TreeNode* root, int sum, vector<int>& entry, vector<vector<int> > &res){
        if(!root) return;
        
        entry.push_back(root->val);
        
        if(root->left == NULL && root->right == NULL){
            if(root->val == sum) res.push_back(entry);
            return;
        } 

        int oriSize = entry.size();
        if(root->left) dfs(root->left, sum - root->val, entry, res);
        entry.resize(oriSize);
        
        if(root->right) dfs(root->right, sum - root->val, entry, res);
    }