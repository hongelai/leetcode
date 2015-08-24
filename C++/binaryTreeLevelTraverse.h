    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        int level = 1;
        if(root) recursiveTraverse(root,level,result);
        else return result;
        return result;
    }
    void recursiveTraverse(TreeNode* root, int level, vector<vector<int>>& result){
        if(!root) return;
        
        if(level > result.size()) result.push_back(vector<int>());
        result[level - 1].push_back(root->val);
        recursiveTraverse(root->left,level+1,result);
        recursiveTraverse(root->right,level+1,result);
    }



    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        if(!root) return result;
        
        queue<TreeNode*> first,second;
        first.push(root);
        
        while(!first.empty()){
            vector<int> res;
            while(!first.empty()){
                TreeNode* tmp = first.front();
                res.push_back(tmp->val);
                first.pop();
                if(tmp->left) second.push(tmp->left);
                if(tmp->right) second.push(tmp->right);
            }
            result.push_back(res);
            swap(first,second);
        }
        return result;
    }