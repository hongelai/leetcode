   //用inorder == root节点算区间大小，在postorder里面每个区间的最后一个是根节点
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTreeRe(inorder,postorder,0,inorder.size()-1,inorder.size()-1);
    }
    TreeNode *buildTreeRe(vector<int> &inorder, vector<int> &postorder, int start, int end, int postIndex){
        if(start > end) return NULL;
        int index = 0;
        while(inorder[index] != postorder[postIndex]) index++;
        int rightNum = end - index;
        TreeNode *root = new TreeNode(postorder[postIndex]);
        root->left = buildTreeRe(inorder,postorder,start,index-1,postIndex-1-rightNum);//postIndex:当前范围根节点的位置；
        root->right = buildTreeRe(inorder,postorder,index+1,end,postIndex-1);
        
        return root;
    }