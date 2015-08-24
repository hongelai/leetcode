#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

struct TreeNode
{
   int val;
   struct TreeNode* left;
   struct TreeNode* right;
   TreeNode(int v):val(v){}
};

struct TreeNode* newnode(int data)
{
  struct TreeNode* node = (struct TreeNode*)
                       malloc(sizeof(struct TreeNode));
  node->val = data;
  node->left = NULL;
  node->right = NULL;
  
  return(node);
}


int main()
{ 
  
  /* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
  */
  struct TreeNode *root = newnode(10);
  root->left        = newnode(8);
  root->right       = newnode(2);
  root->left->left  = newnode(3);
  root->left->right = newnode(5);
  root->right->left = newnode(2);

  return 0;
}