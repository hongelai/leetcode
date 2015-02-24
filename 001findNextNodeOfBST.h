//如果有右节点，next节点在右边的lefmost
//如果没有右节点，next节点是parent：如果该点是左节点，next是其直接parent，若是右节点，要一直往上找successor
Node* minimal(Node* no){
    if(no == NULL) return NULL;
    while(no->lchild)
        no = no->lchild;
    return no;
}
Node* successor(Node* no){  //no 为指定节点指针
    if(no == NULL) return NULL;
    if(no->rchild) return minimal(no->rchild);
    Node *y = no->parent;
    while(y && y->rchild==no){ //如果no是右节点就继续往上，因为只有第一个左节点的parent比他大
        no = y;
        y = y->parent;
    }
    return y;
}



struct node * inOrderSuccessor(struct node *root, struct node *n)
{
    // step 1 of the above algorithm
    if( n->right != NULL )
        return minimal(n->right);
 
    struct node *succ = NULL;
 
    // Start from root and search for successor down the tree
    //因为是二叉查找树，查找比n大的最小节点。 所以从上往下根据大小判断方向，只需要把比n大的点标记为successor。
    while (root != NULL)
    {
        if (n->data < root->data)
        {
            succ = root;
            root = root->left;
        }
        else if (n->data > root->data)
            root = root->right;
        else
           break;
    }
 
    return succ;
}