void splitTree（Node* node, int target, Node* &smalltree, Node* &largetree） {
    if (!node) {
        smalltree = largetree = NULL;
        return;
    }
    if (node -> val == target) {
        smalltree = node -> left;
        largetree = node;
        return;
     }
    if (node -> val > target) {
        largetree = node;
        Node* leftsmall, leftlarge;
        splitTree(node -> left, target, leftsmall, leftlarge);
        node -> left = leftlarge;
        smalltree = leftsmall;
    } else {
        smalltree = node;
        Node* rightsmall, rightlarge;
        splitTree(node -> right, target, rightsmall, rightlarge); 
        node -> right = rightsmall;
        largetree = rightlarge;
}