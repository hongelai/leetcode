#define AlphaBetaSize 26

struct TrieNode
{
  int value;
  TrieNode* child[AlphaBetaSize];
  TrieNode(int val):value(val){}
};

TrieNode* getNode();

struct Trie
{
   TrieNode* root;
   int count;
   Trie(){
      count = 0;
      root = getNode();
   }
};

TrieNode* getNode(){
  TrieNode *node = new TrieNode(0);
  for (int i = 0; i < AlphaBetaSize; ++i)
  {
    node->child[i] = NULL;
  }
  return node;
}

void insert(Trie* trie, string s){
  TrieNode* cur = trie->root;
  trie->count++;

  for (int i = 0; i < s.length(); ++i)
  {
    int index = s[i] - 'a';
    if (cur->child[index] == NULL) cur->child[index] = getNode();
    cur = cur->child[index];
  }
  cur->value = trie->count;
}

bool search(Trie* trie, string s){
  TrieNode* cur = trie->root;

  for (int i = 0; i < s.length(); ++i)
  {
    int index = s[i] - 'a';
    if(cur->child[index] == NULL) return false;
    cur = cur->child[index];
  }
  return cur && cur->value;
}

int main ()
{
  int a[] = {1,1,1,1,2,3,3,4,4,5,5,5,5,6,6,6,6,7,9,9,9,9,9,9,9,9};
  vector<int> v(a,a+26);
  Trie trie;
  string s[] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
  for(int i = 0; i < 8; i++)
  {
      insert(&trie, s[i]);
  }
  cout<<endl;
  cout<<search(&trie,"the")<<endl;
  cout<<search(&trie,"their")<<endl;
	return 0;
}