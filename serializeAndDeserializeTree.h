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