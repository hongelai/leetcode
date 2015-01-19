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

    // Ensure that every next node of in-order traversal is larger than previous one. 
    //Using boolean flag to start with the left most node.
    bool isValidBST(TreeNode *root) {
        
        TreeNode* prev = NULL;
        TreeNode* cur = root;
        stack<TreeNode*> st;
        
        while(cur || !st.empty()){
            if(cur){
                st.push(cur);
                cur = cur->left;
            }else{
                TreeNode* tmp = st.top();
                //visit node
                if(prev){
                    if(tmp->val <= prev->val) return false;
                }
                prev = tmp;
                
                st.pop();
                cur = tmp->right;
            }
        }
        return true;
    }

    // solution 2: inorder recursive
    bool isValidBST_2(TreeNode *root) {
        TreeNode * prev = NULL;
        return inorder(root, prev);
    }
    bool inorder(TreeNode * root, TreeNode*&prev) {
        if (root == NULL) return true;
        if (inorder(root->left, prev) == false) 
            return false;
        if (prev && root->val <= prev->val) return false;
        prev = root;
        return inorder(root->right,prev);
    }