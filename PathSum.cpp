bool hasPathSum(TreeNode *root, int sum) {
    bool leftResult=false,rightResult = false;
    if(root == NULL) return false;
    if(root->left == NULL && root-> right == NULL)
        if(root->val == sum)return true;
        else return false;
    if(root->left != NULL)
        leftResult = hasPathSum(root->left,sum - root->val);
    if(root->right != NULL)
        rightResult = hasPathSum(root->right, sum - root->val);
    return (leftResult || rightResult);
}