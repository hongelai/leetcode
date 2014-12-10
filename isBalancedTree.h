    bool isBalanced(TreeNode *root) {
        if(root == NULL) return true;
        return recursive(root) != -1;
    }
    int recursive(TreeNode* root){
        if(!root) return 0;
        
        int left = recursive(root->left);
        int right = recursive(root->right);
        if(left == -1 || right == -1 || abs(left - right) > 1) return -1;
        
        return max(left,right)+1;
    }