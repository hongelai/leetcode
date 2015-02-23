    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> stk;
        TreeNode *cur = root;

        while (cur || !stk.empty()){
            if (cur){
                res.push_back(cur->val);
                stk.push(cur);
                cur = cur->left;
            }else{
                cur = stk.top()->right;
                stk.pop();
            }
        }
        return res;
    }
//
void in_order_traversal_iterative(BinaryTree *root) {
  stack<BinaryTree*> s;
  BinaryTree *current = root;
  vector<int> res;

  while (!s.empty() || current) { // || current because of first Node root
    if (current) {
      s.push(current);
      current = current->left;
    } else {
      current = s.top();
      s.pop();
      res.push_back(cur->val);  //difference between preorder and inorder
      current = current->right;
    }
  }
}

void postOrderTraversalIterativeTwoStacks(BinaryTree *root) {
  if (!root) return;
  stack<BinaryTree*> s;
  stack<BinaryTree*> output;
  s.push(root);
  while (!s.empty()) {
    BinaryTree *curr = s.top();
    output.push(curr);
    s.pop();
    if (curr->left)
      s.push(curr->left);
    if (curr->right)
      s.push(curr->right);
  }
  while (!output.empty()) {
    cout << output.top()->data << " ";
    output.pop();
  }
}