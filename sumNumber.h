    int sumNumbers(TreeNode *root) {
        return recursive(root,0);
    }
    int recursive(TreeNode* root, int res){
        if(!root) return 0;  //non leaf return 0
        res  = res*10 + root->val;

        if(root->left == NULL && root->right == NULL )return res; // leaf return final value

        return recursive(root->left,res) + recursive(root->right,res);
    }

    //后加
    int sumNumbers(TreeNode *root) {
        queue<pair<TreeNode*,int>> q;
        int res = 0;
        if(root) q.push(make_pair(root,0));
        
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int sum = q.front().second * 10 + node->val;
            q.pop();
            if(node->left == nullptr && node->right == nullptr){
                res += sum;
                continue;
            }
            if(node->left) q.push(make_pair(node->left,sum));
            if(node->right) q.push(make_pair(node->right,sum));
        }
        return res;
    }
    //先加
    int sumNumbers(TreeNode *root) {
        queue<pair<TreeNode*,int>> q;
        int res = 0;
        if(root) q.push(make_pair(root,root->val));
        
        while(!q.empty()){
            TreeNode* node = q.front().first;
            
            if(node->left == nullptr && node->right == nullptr){
                res += q.front().second;
            }
            if(node->left) q.push(make_pair(node->left, q.front().second * 10 + node->left->val));
            if(node->right) q.push(make_pair(node->right, q.front().second * 10 + node->right->val));
            q.pop();
        }
        return res;
    }