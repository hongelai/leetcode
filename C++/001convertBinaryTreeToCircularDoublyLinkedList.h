Node* treeToDoublyList(Node *root) {
  Node *prev = NULL;
  Node *head = NULL;
  treeToDoublyList(root, prev, head);
  return head;
}

void treeToDoublyList(Node *p, Node *& prev, Node *& head) {
    if (!p) return;
    treeToDoublyList(p->left, prev, head);

    //接驳左边
    p->left = prev; //当前节点指向前面
    if (prev)       //如果前面节点不为空的话（非第一个节点），则前面节点指向后面，否则是head
      prev->right = p; 
    else
      head = p; 

    //接驳右边
    Node *right = p->right;//把right节点是next，先保存起来
    head->left = p;
    p->right = head;

    // 更新当前节点位prev
    prev = p;
    treeToDoublyList(right, prev, head);
}

