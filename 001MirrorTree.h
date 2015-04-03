//create a mirror tree of a binary tree
TreeNode* mirrorTree(TreeNode* root){
	if(!root) return NULL;

	TreeNode *newRoot = new TreeNode(root->val);
	newRoot->left = mirrorTree(root->right);
	newRoot->right = mirrorTree(root->left);

	return newRoot;
}



//turn a binary tree into its mirror
//bottom up
void convertToMirror(TreeNode* root){
	if (root == NULL) return; 
	convertToMirror(root->left);
	convertToMirror(root->right);

	TreeNode* tmp = root->left;
	root->left = root->right;
	root->right = tmp;
}
//top down
Node mirrorTree(Node root){
        if(root!=null){
            Node t = root.left;
            root.left = root.right;
            root.right = t;
            mirrorTree(root.right);
            mirrorTree(root.left);
        }
        return root;
}
void MirrorWithoutRecursion(Node * tree)
{
	if (!tree)
		return;

	Stack s;
	s.push(tree);
	while(!s.empty())
	{
		Node * current = s.pop();
		
		// Swap the children
		//
		Node * temp = current->right;
		current->right = current->left;
		current->left = temp;

		// Push the children on the stack
		//
		if (current->right)
			s.push(current->right);

		if (current->left)
			s.push(current->left);
	}
}