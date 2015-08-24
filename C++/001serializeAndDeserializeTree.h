void treeToFile(Node* head, ofstream& target_file)
{
    if(head==NULL){
        target_file<<“#”<<” “;
        return;
    }
    target_file<<head->value<<” “;
    treeToFile(head->left,target_file);
    treeToFile(head->right,target_file);
}

Node* fileToTree(ifstream& input_file)
{
    string s;
    input_file>>s;
    if(s==“#”)
        return NULL;
    while(s==” “)
        input_file>>s;
    Node* head=new Node;
    head->value=atoi(s.c_str());
    head->left=fileToTree(input_file);
    head->right=fileToTree(input_file);
    return head;
}

//same idea
void serializeTree(TreeNode* root, vector<int> &res){
  if (root == NULL)
  {
    res.push_back(-1);
    return;
  }
  res.push_back(root->val);
  serializeTree(root->left, res);
  serializeTree(root->right, res);
}

TreeNode* deserializeTree(vector<int> res, int &index){
  if (res[index] == -1)
  {
    index++;
    return NULL;
  }
  TreeNode *root = new TreeNode(res[index++]);
  root->left = deserializeTree(res, index);
  root->right = deserializeTree(res,index);
  return root;
}