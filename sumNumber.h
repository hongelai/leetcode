    int sumNumbers(TreeNode *root) {
        return recursive(root,0);
    }
    int recursive(TreeNode* root, int res){
        if(!root) return 0;  //non leaf return 0
        res  = res*10 + root->val;

        if(root->left == NULL && root->right == NULL )return res; // leaf return final value

        return recursive(root->left,res) + recursive(root->right,res);
    }