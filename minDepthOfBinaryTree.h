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