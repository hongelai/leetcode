    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int size = preorder.size();
        return buildTreeRe(preorder,inorder,0,size-1,0);
    }
    TreeNode *buildTreeRe(vector<int> &preorder, vector<int> &inorder, int start, int end, int preIndex){
        if(start > end) return NULL;
        
        int index = start;
        while(preorder[preIndex] != inorder[index]) index++;
        int leftNum = index-start;
        TreeNode* root = new TreeNode(preorder[preIndex]);
        root->left = buildTreeRe(preorder,inorder,start,index-1,preIndex+1);
        root->right = buildTreeRe(preorder,inorder,index+1,end,preIndex+leftNum+1);
        
        return root;
    }