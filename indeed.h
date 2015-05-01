//find intersect
vector<int> findIntersect(vector<int> a, vector<int> b){
  int index1 = 0, index2= 0;
  vector<int> res;

  while(index1 < a.size() && index2 < b.size()){
    if (a[index1] == b[index2])
    {
      if(res.size() == 0 || res[res.size()-1] != a[index1]) res.push_back(a[index1]);
      index1++;
      index2++;
    } 
    else if(a[index1] > b[index2]) index2++;
    else index1++;
  } 
  return res;
}

//find union
vector<int> findUnion(vector<int> a, vector<int> b){
  int index1 = 0, index2= 0;
  vector<int> res;

  while(index1 < a.size() && index2 < b.size()){
    if (a[index1] < b[index2])
    {
      if (res.size() == 0 || res.back() != a[index1]) res.push_back(a[index1]);
      index1++;
    } 
    else if(a[index1] > b[index2]){ 
      if (res.size() == 0 || res.back() != b[index2]) res.push_back(b[index2]);
      index2++;
    }
    else{ 
      if (res.size() == 0 || res.back() != a[index1]) res.push_back(a[index1]);
      index1++;
      index2++;
    }
  }
  while(index1 < a.size()){
    if (res.size() == 0 || res.back() != a[index1]) res.push_back(a[index1++]);
  }
  while(index2 < b.size()){
    if (res.size() == 0 || res.back() != b[index2]) res.push_back(b[index2++]);
  }

  return res;
}

//traverse graph by layer
vector<int> BFS(Node* root){
  vector<int> res;
  unordered_set<int> visited;
  queue<Node*> q;

  if(!root) return res;
  q.push(root);
  visited.insert(root->val);

  while(!q.empty()){
    Node* tmp = q.front();
    q.pop();

    for(auto& n : tmp->adj){
      if(visited.count(n->val)) {
        visited.insert(n->val);
        q.push(n);
      }
    }
  }

}


//top k frequent int
void topK(vector<int> a, int k){
  int start = 0, end = 0, count = 0;
  priority_queue<pair<int, int>, vector<pair<int,int> >, comparator > heap;

  while(end < a.size()){
    end = start;
    while(end < a.size() && a[end] == a[start]) end++;
    
    int freq = end - start;
    heap.push(make_pair(a[start], freq));
    count++;
    if (count > k)
    {
      heap.pop();
    }

    start = end;
  }
  while(!heap.empty()){
    cout<<heap.top().first<<" ";
    heap.pop();
  }
}
//top k frequent int n array
struct Node
{
  int val;
  int count;
  Node(int v, int c){
    val = v; 
    count = c;
  }
};

struct comparator
{
  bool operator()(Node* a, Node* b){
    if (a->count == b->count)
    {
      return a->val < b->val;
    }
    return a->count > b->count;
  }
};

void findTopKFrequence(vector<vector<int> > a ,int k){

  unordered_map<int,int> map;
  priority_queue<Node*, vector<Node*>, comparator> heap;
  
  for (int i = 0; i < a.size(); ++i)
  {
    for(int j = 0; j < a[i].size(); j++) map[a[i][j]]++;
  }

  for(auto iter = map.begin(); iter != map.end(); iter++){
    heap.push(new Node(iter->first, iter->second));
    if(heap.size() == k) heap.pop();
  }
  while(!heap.empty()){
    cout<<heap.top()->val<<" ";
    heap.pop();
  }
}

//insert spaces
string fillSpace(string s, int k){
  int sCount = 0;
  for (int i = 0; i < s.length(); ++i)
  {
    if(s[i] == ' ') sCount++;
  }
  int even = (k-s.length())/sCount;
  int remain = (k-s.length())%sCount;
  vector<int> vv(sCount, 0);
  for(int i = 0; i < sCount; i++){
    vv[i] = even;
    if (i < remain)
    {
      vv[i] += 1;
    }
  }
  string res = "";
  for (int i = 0, index = 0; i < s.length(); ++i)
  {
    if (s[i] == ' ')
    {
      res.append(vv[index++]+1, ' ');
    } else {
      res.append(1,s[i]);
    }
  }
}

//repeat word
vector<string> repeatWords(string s){
  unordered_map<string, int> map;
  vector<string> res;
  int len = s.length();

  int start = 0, end = 0;
  while(end < len && s[end] != '\0'){
    while(end < len && s[end] != ' ' && s[end] != '\0') end++;
    start = ++end;
    if(str == " ") continue;
    if(map[str]++ == 1){
      res.push_back(str);
    }
  }

  return res;
}

//merge range
void mergeRange(vector<int> a){
  int start = 0, end = 0;
  int size = a.size();

  while(end < size){
    start = end;
    while(end + 1 < size && a[end] == a[end+1] - 1) end++;
    cout<<a[start]<<"-"<<a[end]<<", ";
    start = ++end;
  }
}

//similarity of two doc
vector<string> split(string s){
  vector<string> res;
  int start = 0, end = 0;
  int count = 0;
  while(end < s.length()){
    start  = end;
    while(end < s.length() && s[end] != '\0' && s[end] != ' ') end++;
    res.push_back(s.substr(start, end- start));
    end++;
  }
  return res;
}

int similarity(string s1, string s2){
  vector<string> v1 = split(s1);
  vector<string> v2 = split(s2);

  int index1 = 0, index2 = 0, res = 0;
  while(index1 < v1.size() && index2 < v2.size()){
    int cnt1 = 0, cnt2 = 0;
    string str = v1[index1] > v2[index2] ? v2[index2] : v1[index1];
    while(v1[index1] == str){ index1++; cnt1++;}
    while(v2[index2] == str){ index2++; cnt2++;}
    res += cnt1 * cnt2;
  } 

  return res;
}

//find integer occur in at least k streams
struct Node
{
  int val;
  int index;
  vector<int>::iterator iter;
  Node(int val, int index, vector<int>::iterator iter):val(val),index(index),iter(iter){};
};

struct comparator
{
  bool operator() (Node* a, Node* b){
    return a->val > b->val;
  }
};

vector<int> numberOccurInAtLeastKStream(vector<vector<int>::iterator> arr,vector<vector<int>::iterator> ends, int k){
  vector<int> res;
  priority_queue<Node*, vector<Node*>, comparator> heap;
  set<int> count;

  for (int i = 0; i < arr.size(); ++i)
  {
    heap.push(new Node(*arr[i], i, arr[i]));
  }
  
  int cur = heap.top()->val;
  while(!heap.empty()){
    Node* tmp  = heap.top();

    if (tmp->val == cur)
    {
      count.insert(tmp->index);
      heap.pop();
      if(++tmp->iter != ends[tmp->index])  heap.push(new Node(*tmp->iter, tmp->index, tmp->iter)); 
    } else {
      if (count.size() >= k) res.push_back(cur);
      count.clear();
      cur = tmp->val;
    }
  }
  return res;
}

//lowest common ancester in graph
//idea: bfs from a and b, color nodes from a as 1, when bfs from b find node colored as 1 then return
char findLowestCommonAncestor(unordered_map<char, string> parent, char a, char b){
  unordered_map<char,int> map;
  queue<char> q;

  for(auto iter = parent.begin(); iter != parent.end(); iter++){
    map[iter->first] = 0;
  }
  q.push(a);
  while(!q.empty()){
    char c  = q.front();
    q.pop();
    map[c] = 1;

    for (int i = 0; i < parent[c].length(); ++i)
    {
      q.push(parent[c][i]);
    }
  }
  q.push(b);
  while(!q.empty()){
    char c  = q.front();
    q.pop();
    if(map[c] == 1) return c;

    for (int i = 0; i < parent[c].length(); ++i)
    {
      q.push(parent[c][i]);
    }
  }
}

//merge with tape
void mergeUtil(vector<int> &a, int low, int mid, int high){
  int i = low, j = mid+1;
  vector<int> tmp;
  while(i <= mid && j <= high){
    if (a[i] < a[j]) tmp.push_back(a[i++]);
    else tmp.push_back(a[j++]);
  }
  if (i <= mid)
  {
    while(i <= mid) tmp.push_back(a[i++]);
  }else {
    while(j <= high) tmp.push_back(a[j++]);
  }
  int index = 0;
  while(index < tmp.size()) a[low++] = tmp[index++];
}

void merge(vector<int> &a){

  for (int gap = 2; gap/2 < a.size(); gap *= 2)
  {
    cout<<gap<<endl;
    for(int j = 0; j < a.size(); j+=gap){
      int mid = j + (gap-1)/2;
      int high = j+gap >= a.size() ? a.size()-1 : j+gap-1;
      mergeUtil(a, j, mid, high);
    }
  }
}
// python check
bool hasControl(string &s){
  int pos = -1;
  if ((pos = s.find("if")) != -1) return true;
  if ((pos = s.find("else")) != -1) return true;
  if ((pos = s.find("for")) != -1) return true;
  return false;
}

int indentSpace(string &s){
  int count = 0;
  while(s[count] == ' ') count++;
  return count;
}

int isValid(vector<string> ss){
  unordered_set<int> indent;
  bool lastIsControl = false;
  int lastIndent = 0;

  for (int i = 0; i < ss.size(); ++i)
  {
    bool isControl = hasControl(ss[i]);
    int indentLine = indentSpace(ss[i]);
    if (i == 0)
    {
      if (indentLine != 0) return i;
    } else {
      if (lastIsControl)
      {
        if (indentLine < lastIndent) return i; 
      } else {
        if(indentLine != lastIndent && indent.count(indentLine) == 0) return i;
      }
    }
    lastIsControl = isControl ? true : false;
    lastIndent = indentLine;
    if(isControl) indent.insert(indentLine);
  }

  return -1;
}

//excel
    string convertToTitle(int n) {
        
        string res="";
        while(n >= 0){
            res = (char)((n)%3 + 'A') +res;
            n = (n) / 3 - 1;
        }

        return res;
    }

