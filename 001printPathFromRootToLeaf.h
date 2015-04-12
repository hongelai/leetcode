void printPath(TreeNode* root){
	vector<string> pathInfo;
	if(root == NULL) return;
	else printPathRe(root, pathInfo, 0)
}
void printPathRe(TreeNode* root, vector<string> &path, int len){
	if (root == NULL) return;
	
	if(path.size() <= len) path.push_back(root->val);
	else path[len] = root->val;
	len++;
	
	if (root->left == NULL && root->right == NULL) {
		printResult(path, len);
	} else {
		printPathRe(root->left, path, len);
		printPathRe(root->right, path, len);
	}
}
void printResult(vector<string> path, int len) {
	for(int i = 0; i < len; i++) cout<<path[i]<<" ";
	cout<<endl;
}


//iterative
void printStack(vector<TreeNode*> path){
  for(int i = 0; i < path.size(); i++) cout<<path[i]->val<<" ";
  cout<<endl;
}

void printPath_iterative(TreeNode* root){
  vector<TreeNode*> sk;
  unordered_set<TreeNode*> visited;

  if(root ==  NULL) return;
  sk.push_back(root);
  while (!sk.empty()){

    TreeNode* tmp = sk.back();
    
    if (tmp->left && visited.count(tmp->left) == 0){
      sk.push_back(tmp->left);
    } else if (tmp->right && visited.count(tmp->right) == 0){
      sk.push_back(tmp->right);
    } else {
      if(tmp->left == NULL && tmp->right == NULL) printStack(sk);
      visited.insert(tmp);
      sk.pop_back();
    }
  }
}