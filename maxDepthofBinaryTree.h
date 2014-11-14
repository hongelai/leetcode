class Solution {
public:
    int maxDepth(TreeNode *root) {
    	queue<TreeNode*> Q;
    	int depth = 0;
    	int count = 1;
    	TreeNode* curr;
    	if(root){
          	Q.push(root);
    	}
    	while(!Q.empty())
    	{
    		curr = Q.front();
    		if(curr->left)
    			Q.push(curr->left);
    		if(curr->right)
    			Q.push(curr->right);
    		Q.pop();
    		count--;
    
    		if (count == 0)
    		{
    			depth++;
    			count = Q.size();
    		}
    	}
    	return depth;
    }
};
class Solution {
public:
    int maxDepth(TreeNode *root) {
    	if (root == NULL)
    		return 0;
    	return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};