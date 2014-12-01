void in_order_traversal_iterative(BinaryTree *root) {
  stack<BinaryTree*> s;
  BinaryTree *current = root;
  while (!s.empty() || current) {
    if (current) {
      s.push(current);
      current = current->left;
    } else {
      current = s.top();
      s.pop();
      cout << current->data << " ";
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