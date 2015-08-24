   //solution 1: bottom up
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

    //solution 2 ： root->leaf
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return buildBST(num, 0, num.size() - 1);
    }
    
    TreeNode *buildBST(vector<int> &num, int start, int end)
    {
        if (start > end) return NULL;

        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = buildBST(num, start, mid - 1);
        root->right = buildBST(num, mid + 1, end);

        return root;
    }