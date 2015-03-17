    int maxPathSum(TreeNode *root) {
        //借鉴最大连续子序列这题思路，如果左右子树结果大于0 则表示有贡献，否则抛弃，res记录最大值
        int res = INT_MIN;
        maxPathSumRe(root, res);
        
        return res;
    }
    int maxPathSumRe(TreeNode *root, int &res) {
        if(!root) return 0;
        
        int left = maxPathSumRe(root->left, res);
        int right = maxPathSumRe(root->right, res);
        int sum = max(max(left, right)+root->val, root->val); //如果左右都小于0，则sum从当前点重新开始算
        res = max(res, max(left, 0) + max(right, 0) + root->val);//求包括当前节点在内的最大值。res里面是从left和right算出来的最大值，如果左右节点返回的sum加上当前点的值不够大就保留原来的。
        return sum;
    }