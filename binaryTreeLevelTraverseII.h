    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> result;
        if(!root) return result;
        else reTraverse(root,1,result);
        reverse(result.begin(),result.end());
        return result;
    }
    void reTraverse(TreeNode* root, int level, vector<vector<int>> &result){
        if(!root) return;
        
        if(level > result.size()) result.push_back(vector<int>());
        result[level-1].push_back(root->val);
        reTraverse(root->left,level+1,result);
        reTraverse(root->right,level+1,result);
    }

    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> result;
        if(!root) return result;
        queue<TreeNode*> first,second;
        vector<int> res;
        first.push(root);
        while(!first.empty()){
            while(!first.empty()){
                TreeNode* tmp = first.front();
                res.push_back(tmp->val);
                first.pop();
                if(tmp->left) second.push(tmp->left);
                if(tmp->right) second.push(tmp->right);
            }
            result.push_back(res);
            res.clear();
            swap(first,second);
        }
        reverse(result.begin(),result.end());
        return result;
    }