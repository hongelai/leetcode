int longRe(TreeNode* root, int &res){

  if(!root) return 0;
  int left = longRe(root->left, res);
  int right  = longRe(root->right, res);
  int sum = max(left,right) + 1;
  res = max(res, left+right+1);
  return sum;
}
int longestPathLength(TreeNode* root){
  int res = 0;
  longRe(root, res);
  return res;
}