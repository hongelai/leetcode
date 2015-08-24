/* 
  See http://www.geeksforgeeks.org/archives/632 for implementation of size()
 
  See Method 3 of http://www.geeksforgeeks.org/archives/3042 for
  implementation of isBST() 
 
  max() returns maximum of two integers 
*/  
int largestBST(struct node *root)
{
   if (isBST(root))
     return size(root); 
   else
    return max(largestBST(root->left), largestBST(root->right));
}