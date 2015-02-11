    void recoverTree(TreeNode *root) {
        //serialize the tree and switch that two node is not in increasing order
        vector<TreeNode*> vt;
        inOrderTraversal(root, vt);
        TreeNode *first = NULL, *second = NULL;
        
        for (int i = 1; i < vt.size(); i++) {
            if (vt[i]->val < vt[i-1]->val) {
                if(first == NULL) first = vt[i-1];
                second = vt[i];
            }
        }
        swap(first->val, second->val);
    }
    void inOrderTraversal(TreeNode *root, vector<TreeNode*> &vt){
        if (root->left) inOrderTraversal(root->left, vt);
        vt.push_back(root);
        if (root->right) inOrderTraversal(root->right, vt);
    }