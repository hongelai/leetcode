class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p == NULL || q == NULL)
            if(p == NULL && q == NULL)
                return true;
            else 
                return false;
        return (isSameTree(p->left,q->left) == true && isSameTree(p->right,q->right) == true && p->val == q->val) ? true :false; 
    }
};