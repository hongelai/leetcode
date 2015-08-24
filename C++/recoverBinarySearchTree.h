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

    //solution 2 : keep track of node when traveral
    void recoverTree(TreeNode *root) {
        if (!root) return;
        TreeNode *first = NULL, *second = NULL, *prev = NULL;
        inOrderSolve(root, first, second, prev);
        if(first != NULL) swap(first->val, second->val);
    }
    void inOrderSolve(TreeNode *root, TreeNode* &first, TreeNode* &second, TreeNode* &prev){
        if(root == NULL) return;
        inOrderSolve(root->left, first, second, prev);
        if(prev && prev->val >= root->val) {
            if (first == NULL){
                first = prev;
            }
            second = root;
        }
        prev = root;
        inOrderSolve(root->right, first, second, prev);
    }

    //morris traveral O(1) space
    void recoverTree(TreeNode *root) {
        if(root == NULL) return;
        TreeNode *first = NULL, *second = NULL, *last = NULL, *cur = root;
        
        while(cur != NULL) {
            if (cur->left == NULL) {
                compare(last, cur, first, second);
                last = cur;
                cur = cur->right;
            } else {
                TreeNode *prev = cur->left;
                while(prev->right && prev->right != cur) prev = prev->right;
                
                if(prev->right == NULL) { //first time to visit this node
                    prev->right = cur;
                    cur = cur->left;
                } else { //second time visit
                    compare(last, cur, first, second);
                    last = cur;
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }
        swap(first->val, second->val);
    }
    void compare(TreeNode *last, TreeNode *cur, TreeNode *&first, TreeNode *&second){
        if(last != NULL && last->val >= cur->val){
            if(first == NULL){
                first = last;
            }
            second = cur;
        }
    }