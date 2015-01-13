//serrialize the tree with inorder traversal, then store it in vector, access nodes as list using index
//memory
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        if(root) index = 0;
        else index = -1;
        
        stack<TreeNode*> stn;
        TreeNode* pt = root;

        while(!stn.empty() || pt){        //in order traversal
            if(pt){           //if not null
                stn.push(pt);
                pt = pt->left; // keep going left
            }else{
                pt = stn.top();
                vt.push_back(pt);
                stn.pop();
                pt = pt->right;
            }
            
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(index >=0 && index < vt.size()) return true;
        else return false;
    }

    /** @return the next smallest number */
    int next() {
        if(index >=0 && index < vt.size()){
            TreeNode* tmp = vt[index++];
            return tmp->val;
        }
    }
private:
    int index;
    vector<TreeNode*> vt;
};


class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        node = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(s.empty() && node == NULL) return false;
        else return true;
    }

    /** @return the next smallest number */
    int next() {     //'node' record the cur position, and always return the leftest node starting from current position
        if(s.empty() && node == NULL) return 0;

        while(node){
            s.push(node);
            node = node->left;
        }
        node = s.top();
        s.pop();
        int res = node->val;
        node = node->right;
        return res;  
    }
private:
    TreeNode* node;
    stack<TreeNode*> s;
};