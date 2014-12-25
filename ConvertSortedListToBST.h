    TreeNode *sortedListToBST(ListNode *head) {
        //inorder recover, devide list by decreasing length 
        return inOrderRecover(head,getLength(head));
    }
    
    TreeNode* inOrderRecover(ListNode* &head, int length){
        if(length == 0) return NULL;
        int mid = length / 2;
        
        TreeNode* left = inOrderRecover(head,mid);
        TreeNode* root = new TreeNode(head->val); 
        head = head->next;
        TreeNode* right = inOrderRecover(head,length-mid-1); //important to update head->next,minus one because mid element does not count
        
        root->left = left;
        root->right = right;
       
        return root;
    }
    
    int getLength(ListNode* head){
        int res = 0;
        while(head){
            res++;
            head = head->next;
        }
        return res;
    }