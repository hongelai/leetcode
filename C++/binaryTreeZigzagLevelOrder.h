    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        
        queue<TreeNode*> first,second;
        vector<vector<int> > res;
        bool revert = false;
        
        if(root) first.push(root);
        
        while(!first.empty()){
            vector<int> entry;
            while(!first.empty()){
                TreeNode* tmp = first.front();
                first.pop();
                if(tmp->left) second.push(tmp->left);
                if(tmp->right) second.push(tmp->right);
                entry.push_back(tmp->val);
            }
            swap(first,second);
            if(revert) reverse(entry.begin(),entry.end());
            res.push_back(entry);
            revert = !revert;
        }
        return res;
    }
    //use stack to avoid reverse
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        stack<TreeNode*> first, second;
        vector<vector<int> > ret;
        if(root == NULL) return ret;
        first.push(root);
        bool left2right = true;
        
        while(!first.empty()) {
            vector<int> level;
            while(!first.empty()){
                TreeNode *tmp = first.top();
                first.pop();
                level.push_back(tmp->val);
                if(left2right){
                    if(tmp->left) second.push(tmp->left);
                    if(tmp->right) second.push(tmp->right);
                } else {
                    if(tmp->right) second.push(tmp->right);
                    if(tmp->left) second.push(tmp->left);
                }
            }
            ret.push_back(level);
            swap(first, second);
            left2right = !left2right;
        }
        return ret;
    }
    
    //use NULL as level indicator, great trick
     vector<vector<int>> zigzagLevelOrder_1(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);   // end indicator of one level
        bool left2right = true;
        vector<int> level;
        while (true)
        {
            TreeNode *node = q.front(); q.pop();
            if (node)
            {
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            else
            {
                if (!left2right) 
                    reverse(level.begin(), level.end());
                res.push_back(level);
                level.clear();
                if (q.empty()) break;
                q.push(NULL);
                left2right = !left2right;
            }
        }
        return res;
    }