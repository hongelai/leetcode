    vector<TreeNode *> generateTrees(int n) {
        return generateTreesRe(1,n);
    }
    vector<TreeNode*> generateTreesRe(int left, int right){
        vector<TreeNode*> res;
        if(left > right){
            res.push_back(NULL);
            return res;
        } 
        
        for(int k = left; k <= right; k++){ // all node in the left less than k, nodes in the right greater than k
            
            vector<TreeNode*> leftTrees = generateTreesRe(left,k-1);
            vector<TreeNode*> rightTrees = generateTreesRe(k+1,right);
            
            for(int i = 0; i < leftTrees.size(); i++)
                for(int j = 0; j < rightTrees.size(); j++){
                    
                    TreeNode* entry = new TreeNode(k);
                    entry->left = leftTrees[i];
                    entry->right = rightTrees[j];
                    res.push_back(entry);
                }
        }
        return res;
    }