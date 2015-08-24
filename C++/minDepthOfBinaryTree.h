    int minDepth(TreeNode *root) {
        int depth = 1;
        if(root == NULL) return 0;
        if(root->left != NULL || root->right != NULL){
            if(root->left == NULL) depth += minDepth(root->right);
            else if(root->right == NULL) depth += minDepth(root->left);
            else depth += min(minDepth(root->left),minDepth(root->right));
            
        } 
        return depth;
    }

    int minDepth(TreeNode *root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        
        int left = INT_MAX, right = INT_MAX;
        if(root->left) left = minDepth(root->left);
        if(root->right) right = minDepth(root->right);
        return min(left, right) + 1; 
    }

    //iterative: use NULL as level seperator
    int minDepth(TreeNode *root) {
        if(root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int depth = 1;
        
        while(!q.empty()) {
            TreeNode *tmp = q.front();
            q.pop();
            if(tmp && tmp->left == NULL && tmp->right == NULL) { //is leaf node
                return depth;
            }
            if(tmp == NULL) {
                
                depth++;
                continue;
            }
            if(tmp->left) q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
            if(q.front() == NULL) q.push(NULL);
        }
    }
    //iterative : use count to keep track of layer
    int minDepth(TreeNode *root) {
        if(root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 1, count = 1;
        
        while(!q.empty()) {
            TreeNode *tmp = q.front();
            q.pop();
            count--;
            
            if(tmp->left == NULL && tmp->right == NULL) {
                return depth;
            }
            
            if(tmp->left) q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
            
            if(0 == count) {
                depth++;
                count = q.size();
            }
        }
    }