//不管有没有有右子树，找到最右。如果最右有左子树，找左子树最大（最右），没有左子树，返回父亲节点
TreeNode *findSecond(TreeNode *root) {
	if (root == NULL || (root->left && root->right == NULL))  return NULL;
	TreeNode *parent = NULL, cur = root;
	while (cur->right) {
		cur = parent;
		cur = cur->right;
	}
	if (cur->left)
	{
		cur = cur->left;
		while(cur->right) cur = cur->right;
		return cur;
	} else {
		return parent;
	}
}
//代码未经验证