struct Node *findLCA(struct Node* root, int n1, int n2)
{
    // Base case
    if (root == NULL) return NULL;
 
    // If either n1 or n2 matches with root's key, report
    // the presence by returning root (Note that if a key is
    // ancestor of other, then the ancestor key becomes LCA
    if (root->key == n1 || root->key == n2)
        return root;
 
    // Look for keys in left and right subtrees
    Node *left_lca  = findLCA(root->left, n1, n2);
    Node *right_lca = findLCA(root->right, n1, n2);
 
    // If both of the above calls return Non-NULL, then one key
    // is present in once subtree and other is present in other,
    // So this node is the LCA
    if (left_lca && right_lca)  return root;
 
    // Otherwise check if left subtree or right subtree is LCA
    return (left_lca != NULL)? left_lca: right_lca;
}
 
 //for binary search tree
struct node *lca(struct node* root, int n1, int n2)
{
    if (root == NULL)
    return NULL;
 
    if (root->data > n1 && root->data > n2)
        return lca(root->left, n1, n2);
 
    if (root->data < n1 && root->data < n2)
        return lca(root->right, n1, n2);
 
    return root;
}

//n-ary tree
Node LCA(Node a, Node b, Node root)
    {
        if(a == root || b == root)
            return root;
            
        int count = 0;
        Node temp = null;
        
        for(Node iter : root.children)
        {
            Node res = LCA(a, b, iter);
            if(res != null)
            {
                count++;
                temp = res;
            }
        }
        
        if(count == 2)
            return root;
            
        return temp;
    }