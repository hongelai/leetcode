//create a mirror tree of a binary tree
TreeNode* mirrorTree(TreeNode* root){
	if(!root) return NULL;

	TreeNode *newRoot = new TreeNode(root->val);
	newRoot->left = mirrorTree(root->right);
	newRoot->right = mirrorTree(root->left);

	return newRoot;
}
//turn a binary tree into its mirror
void convertToMirror(TreeNode* root){
	convertToMirror(root->left);
	convertToMirror(root->right);

	TreeNode* tmp = root->left;
	root->left = root->right;
	root->right = tmp;
}