    //use long long to avoid edge case , not a good idea
    bool isValidBST(TreeNode *root) {
        if(root) return validBST(root,LONG_MIN,LONG_MAX);
        else return true;
    }
    bool validBST(TreeNode* root, long long low, long long high){
        bool isBST = root->val > low && root->val < high;
        
        if(root->left) isBST &= validBST(root->left,low,root->val);
        if(root->right) isBST &= validBST(root->right,root->val,high);
        
        return isBST;
    }

    // use inorder traverse to bottom up