//map implementation, in c++ map is implemented using red-black tree
class Trie
{
private:
  char value;
  map<char, Trie*> children;
  bool flag;
public:
  Trie(char val = ' '){
    value = val;
    flag = false;
  }
  void insert(string s);
  bool search(string s);
  vector<string> getWords();
  friend void dfs(vector<string> &res, string &path, Trie* trie);
};

void Trie::insert(string s){
  Trie* cur = this;

  for (int i = 0; i < s.length(); ++i)
  {
    char c = s[i];
    if(cur->children.count(c) == 0){
      cur->children[c] = new Trie(c);
    }
    cur = cur->children[c];
  }
  cur->flag = true;
}

bool Trie::search(string s){
  Trie* cur = this;

  for (int i = 0; i < s.length(); ++i)
  {
    char c = s[i];
    if (cur->children.count(c) != 0)
    {
      cur = cur->children[c];
    } else return false;
  }
  return cur->flag;
}

void dfs(vector<string> &res, string &path, Trie* trie){
  if (trie->flag)
  {
    res.push_back(path);
  }
  //map key is like edge, map trie->value store trie node value; value == key
  for(auto it = trie->children.begin(); it != trie->children.end(); it++){
    char c = it->second->value;
    path.append(1,c);
    dfs(res,path,it->second);
    path.pop_back();
  }
}

vector<string> Trie::getWords(){
  Trie* trie = this;
  string path;
  vector<string> res;
  dfs(res,path,trie);
  return res;
}

//array implementation
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