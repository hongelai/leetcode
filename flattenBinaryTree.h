    void flatten(TreeNode *root) {
        if(root == NULL) return;
        if(root->left){
            if(root->right){
                TreeNode* tmp = root->left;
                while(tmp->left|| tmp->right){ //find the biggest in the left
                    if(tmp->right) tmp = tmp->right;
                    else tmp = tmp->left;
                }
                tmp->right = root->right;
            }
            root->right = root->left;
            root->left = NULL;
            
        }
        if(root->right) flatten(root->right);
    }