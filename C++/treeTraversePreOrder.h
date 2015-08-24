    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> s;
        if(root) s.push(root);

        while(!s.empty()){
            TreeNode* tmp = s.top();
            res.push_back(tmp->val);
            s.pop();
            if(tmp->right) s.push(tmp->right);
            if(tmp->left) s.push(tmp->left);
        }
        return res;
    }

    vector<int> preorderTraversal_1(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> stk;
        TreeNode *cur = root;

        while (cur || !stk.empty()){
            if (cur){
                res.push_back(cur->val);
                stk.push(cur);
                cur = cur->left;
            }else{
                cur = stk.top()->right;
                stk.pop();
            }
        }
        return res;
    }