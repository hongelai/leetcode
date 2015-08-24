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

    //change recursive to iterative, greatly speed up the code
    void flatten(TreeNode *root) {
        if(root == NULL) return;
        TreeNode *cur = root;
        
        while(cur) {
            if(cur->left){
                if(cur->right){
                    TreeNode* tmp = cur->left;
                    while(tmp->right){ //find the biggest in the left
                        tmp = tmp->right;
                    }
                    tmp->right = cur->right;
                }
                cur->right = cur->left;
                cur->left = NULL;
                
            }
            cur = cur->right;
        }
    }