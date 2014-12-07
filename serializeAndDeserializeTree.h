01 void treeToFile(Node* head, ofstream& target_file)
02 {
03     if(head==NULL){
04         target_file<<“#”<<” “;
05         return;
06     }
07     target_file<<head->value<<” “;
08     treeToFile(head->left,target_file);
09     treeToFile(head->right,target_file);
10 }
11 
12 Node* fileToTree(ifstream& input_file)
13 {
14     string s;
15     input_file>>s;
16     if(s==“#”)
17         return NULL;
18     while(s==” “)
19         input_file>>s;
20     Node* head=new Node;
21     head->value=atoi(s.c_str());
22     head->left=fileToTree(input_file);
23     head->right=fileToTree(input_file);
24     return head;
25 }