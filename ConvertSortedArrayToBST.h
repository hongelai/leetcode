    TreeNode *sortedArrayToBST(vector<int> &num) {
        int index = 0;
        return inOrderRecover(num,index,num.size());
    }
    TreeNode* inOrderRecover(vector<int> &num, int& index, int size){
        if(size == 0) return NULL; 

        int mid = size /2 ;
        TreeNode* left = inOrderRecover(num,index,mid);
        TreeNode* root = new TreeNode(num[index++]);
        TreeNode* right = inOrderRecover(num,index,size-mid-1);
        
        root->left = left;
        root->right = right;
        
        return root;
    }