// 成就系统 蓄水池 议员选举 （workbreakI dfs写法）（setcharAT tree解法）
//
// top k 
class comparator
{
public:
  bool operator() (pair<int,int> a, pair<int, int> b) {
    return a.second > b.second;
  }
};
vector<int> topK(vector<int> v, int k) {
  unordered_map<int, int> map;
  vector<int> res;

  for(int i = 0; i < v.size(); i++) {
    map[v[i]]++;
  }
  priority_queue<pair<int,int>, vector<pair<int,int> >, comparator> q; //min heap
  int count = 0;
  for (auto it = map.begin(); it != map.end(); it++) {
    count++;
    q.push(make_pair(it->first,it->second));
    if(count > k) q.pop();
  }
  while(!q.empty()) {
    res.push_back(q.top().first);
    q.pop();
  }
  return res;
}

// work break
string wordBreak(string s, unordered_set<string> &dict) {
    int size = s.size();
    vector<bool> dp(size+1,false);
    dp[0] = true;
    unordered_map<int,int> map;

    for(int i = 0; i < size; i++){
        if(dp[i]){
            for(int  j = i; j < size; j++){
               string sub = s.substr(i,j - i + 1);
               if(dict.find(sub) != dict.end()){ 
                  dp[j+1] = true;
                  map[j+1] = i;
              } 
            }
        }
    }

    string res = "";
    if (!dp[size]) return res;
    else{
      int n = size;
      while(map.count(n) != 0) {
        res = s.substr(map[n], n- map[n]) + " " + res;
        n = map[n];
      }
    }
    res.pop_back();
    return res;
}

// max inside sliding window
vector<int> maxArray(vector<int> a, int k) {
  deque<int> q;
  vector<int> res;
  int size = a.size();

  for (int i = 0; i < k && i < size; i++) {
    while (!q.empty() && q.back() < a[i]) q.pop_back();
    q.push_back(a[i]);
  }

  for (int i = 0; i <= size - k; i++) {
    res.push_back(q.front());
    while(!q.empty() && q.back() < a[i+k]) q.pop_back();
    q.push_back(a[i+k]);
    if (a[i] == q.front()) q.pop_front();
  }
  return res;
}


//max product subarray
    int maxProduct(int A[], int n) {
        if(n == 0) return 0;
        
        int maxRes = A[0], minRes = A[0],result = A[0];
        for(int i = 1; i < n; i++){
            int tempMax = maxRes;
            //包含第i 的三种情况，A[i]本身， max* A[i]， min*A[i]
            maxRes = max(A[i],max(minRes*A[i],A[i]*maxRes));
            minRes = min(A[i],min(minRes*A[i],A[i]*tempMax));
            if(maxRes > result){
                result = maxRes;
            }
        }
        return result;
    }

//longest palindrom substring
    string longestPalindrome(string s) {
        int length = s.length();
        // vector<vector<bool> > dp(length,vector<bool>(length)); // time limit exceeded
        bool dp[1000][1000] = {false};
        string res= "";
        int max = 0;
        int start = 0, end = length -1;
        
        for(int i = length - 1 ; i >= 0; i--)
            for(int j = i; j < length; j++){
                dp[i][j] = (s[i]==s[j]) && (i+2 > j || dp[i+1][j-1]);
                if(dp[i][j] && j - i >= max){
                    max = j - i + 1;
                    start = i;
                    end = j;
                }
            }
        return s.substr(start,end-start+1);
    }

//binary tree top down view
struct item
{
  int dist;
  TreeNode* node;
  item(int dist, TreeNode* node):dist(dist), node(node){};
};
vector<int> topDownView(TreeNode* root){
  vector<int> res;
  unordered_set<int> mySet;
  if (root == NULL) return res;
  queue<item*> q;
  q.push(new item(0, root));
  int maxI = 0, minI = 0;

  while(!q.empty()) {
    item* tmp = q.front();
    q.pop();
    
    // if(mySet.count(tmp->dist) == 0){
    //   mySet.insert(tmp->dist);
    //   res.push_back(tmp->node->val);
    // }
    // 
    if(tmp->dist > maxI || tmp->dist < minI){
      res.push_back(tmp->node->val);
      maxI = max(maxI, tmp->dist);
      minI = min(minI, tmp->dist);
    }
    if(maxI == minI){
      res.push_back(tmp->node->val);
    }

    if(tmp->node->left) q.push(new item(tmp->dist - 1, tmp->node->left));
    if(tmp->node->right) q.push(new item(tmp->dist + 1, tmp->node->right));
  }
  return res;
}


//shortest uique string
string uiqueString(vector<string> v) {
  unordered_map<char, unordered_set<char> > map;// char--- chars pointing to char
  unordered_set<char> chars;
  stack<char> zero_degree;
  string res;

  for (int i = 0; i < v.size(); ++i)
  {
    chars.insert(v[i][0]);
    for (int j = 1; j < v[i].size(); ++j){
       map[v[i][j]].insert(v[i][j-1]);
       chars.insert(v[i][j]);
     }
  }

  for (auto it = chars.begin(); it != chars.end(); it++)
  { 
    if(map.count(*it) == 0){
      zero_degree.push(*it);
    }
  }
  while (!zero_degree.empty()) {
    char c = zero_degree.top();
    zero_degree.pop();
    res.push_back(c);

    for (auto it = map.begin(); it != map.end(); it++)
    {
      if(it->second.size() != 0 && it->second.count(c) != 0){
        it->second.erase(c);
        if(it->second.size() == 0){
           zero_degree.push(it->first);
        }
      }
    }
  }
  return res;
}
//using child 
class myChar
{
public:
  char c;
  int degree;
  unordered_set<char> childs;
  myChar(char c, int d):c(c),degree(d){};
 };
string uiqueString(vector<string> v) {
  unordered_map<char, myChar*> map;
  stack<char> zero_degree;
  string res;

  for (int i = 0; i < v.size(); ++i)
  {
    for (int j = 0; j < v[i].size()-1; ++j){
      if (map[v[i][j]] == NULL)
      {
        map[v[i][j]] = new myChar(v[i][j], 0);
      }
      if (map[v[i][j+1]] == NULL)
      {
        map[v[i][j+1]] = new myChar(v[i][j+1], 0);
      }
       map[v[i][j]]->childs.insert(v[i][j+1]);
       map[v[i][j+1]]->degree++;
     }
  }
  for (auto it = map.begin(); it != map.end(); it++)
  { 
    if(it->second->degree == 0){
      zero_degree.push(it->first);
    }
  }
  while (!zero_degree.empty()) {
    char c = zero_degree.top();
    zero_degree.pop();
    res.push_back(c);

    for (auto it = map[c]->childs.begin(); it != map[c]->childs.end(); it++)
    {
      map[*it]->degree--;
      if (map[*it]->degree == 0)
      {
        zero_degree.push(*it);
      }
    }
  }
  return res;
}

//minimize set diff
int balancePartition(int set[], int n){
 /*The value of subset[i][j] will be true if there is a subset 
     of set[0..j-1] with sum equal to i */
        int i,j;
        int sum =0;
 
        for(i =0; i<=n; i++){
                sum += set[i];
        }
 
        int subset[sum+1][n+1];
        // If sum is 0, then answer is true
        for (i = 0; i <= n; i++)
                subset[0][i] = true;
 
        // If sum is not 0 and set is empty, then answer is false
        for (i = 1; i <= sum; i++)
                subset[i][0] = false;
 
        // Fill the subset table in botton up manner
        for (i = 1; i <= sum; i++){
         for ( j = 1; j <= n ; j++){
           subset[i][j] = subset[i][j-1];
           if (i >= set[j-1]){
              subset[i][j] = subset[i][j] ||subset[i-set[j-1]][j-1];
           }
         }
        }
 
        int min =INT_MAX;
    
        for(i=1; i<=sum; i++){
            if(subset[i][size] == true){    //sum[i][size] == sum[sum-i][size] == true;
                 if(abs(sum - 2*i) < min){  // minimize the diff (i, sum-i)
                     min  = abs(sum - 2 *i);
                 }
            }
        }
 
        printf("\n Differece between two sub sets will be : %d\n", min);
}


//maximize pizza area
//p( i, j ) = max ( A[i] + min ( p(i+2, j), p(i+1, j-1) ), A[j] + min( p(i, j-2), p(i+1, j-1) ) )
void printMoves(vector<vector<int> > dp, vector<int> A) {
  int i = 0, j = A.size()-1;
  bool myTurn = true;
  while (i < j) {
    int p1 = dp[i+1][j];
    int p2 = dp[i][j-1];
    if(p1 <= p2) { //minimize opponent
        if(myTurn) cout<<A[i]<<" ";
        i++;
    }else {
      if (myTurn) cout<<A[j]<<" ";
      j--;
    }
    myTurn = !myTurn;
  }
}
int maxPizza(vector<int> A) {
  int size = A.size();
  vector<vector<int> > dp(size, vector<int>(size, 0));
  int a, b, c;
  //目标是求矩阵右上角的值，而且i 《 j， 所以每次求出一条对角线的值，gap+1 挪到下一跳对角线
  for (int gap = 0;  gap < size; gap++)
    for (int i = 0, j = gap; j < size; i++, j++) {
      a = i+2 < j ? dp[i+2][j] : 0;
      b = i+1 < j-1 ? dp[i+1][j-1] : 0;
      c = i < j-2 ? dp[i][j-2] : 0;
      dp[i][j] = max(A[i] + min(a,b) , min(b,c) + A[j]);
    }
    printMoves(dp, A);
    return dp[0][size-1];
}


//good number
void primeFactors(int n)
{
    // Print the number of 2s that divide n
    while (n%2 == 0){
        printf("%d ", 2);
        n = n/2;
    }
 
    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2){
        // While i divides n, print i and divide n
        while (n%i == 0){
            printf("%d ", i);
            n = n/i;
        }
    }
    if (n > 2)
        printf ("%d ", n);
}

//football game
void dfs(vector<pair<int,int> > &entry, int i, int j, int m, int n) {
  if(i > m || i < j) return;
  if(i == m && j == n) {
    entry.push_back(make_pair(m,n));
    for(int i = 0; i < entry.size(); i++) cout<<"("<<entry[i].first<<","<<entry[i].second<<")"<<" ";
      cout<<endl;
      entry.pop_back();
    return;
  }
  
  if (i < m){
    entry.push_back(make_pair(i,j));
    dfs(entry,i+1,j,m,n);
    entry.pop_back();
  }
  if(j < n){
    entry.push_back(make_pair(i,j));
    dfs(entry,i,j+1,m,n);
    entry.pop_back();
  }
}
void football(int m, int n) {
  vector<pair<int,int> > entry;
  dfs(entry, 0, 0, m, n);
}

//蓄水池
/*
选择策略：1。 从1-i个数随机选取一个数，如果选到第i个数 就用第i个数替换 从1--i 里面选到的数
          2.要是选不到 第i个数 ，就保留 从1--i里面选的数

      证明：1.设 i-1 个数的概率是1/(i-1)
          2. 对于 i个数，
            抽到第i个数的概率是 1/i
            要是没抽到i，那么保留前i-1个数的结果，对于前i-1个数来说，选到的概率是 (1 - 1/i) * (1/(i-1)) = 1/i



          策略：抽到第1--k之间的数就用第i个数来替换，否则k个数保留不变

          k/(i-1) * ((i-k)/i + (k-1)/k * k/i)

          要是选k个数，选到第i个数的概率是 k/i
          对于前i-1个数被选到的概率是
*/


//matrix k round
bool checkK(int x, int y, int k) {
  int sum = 0;
  x = abs(x), y = abs(y);
  while(x) {
    sum += x%10;
    x /= 10;
  }
  while(y){
    sum += y%10;
    y /= 10;
  }
  return sum <= k ? true : false;
}
void dfs(int x, int y, unordered_map<int, unordered_set<int> > &map, vector<pair<int, int> > &res, int k) {
  if(!checkK(x,y,k)) return;
  if(map[x].count(y) == 0){
     res.push_back(make_pair(x,y));
     map[x].insert(y);
   }
  else return;
  // if(x == 0)cout<<"("<<x<<","<<y<<")"<<endl;
  dfs(x-1,y, map, res, k);
  dfs(x+1,y, map, res, k);
  dfs(x,y-1, map, res, k);
  dfs(x,y+1, map, res, k);
}
void getPoints(int k) {
  vector<pair<int, int> > res;
  unordered_map<int, unordered_set<int> > map;
  dfs(0, 0, map, res, k);
  cout<<res.size()<<endl;
}


//charAt substring
//O(1) space
class myString
{
  string str;
  int size;
  int offset;
  myString* parent;
  unordered_map<int, char> change;
public:
  myString(string &str, int offset, int size, myString* parent = NULL):str(str),offset(offset), parent(parent){};
  char charAt(int index){
    myString* cur = this;
    while (cur->parent != NULL && cur->change.count(index) == 0)
    {
      cur = parent;
    }  
    if (cur->parent == NULL && cur->change.count(index) == 0)
    {
      return cur->str[index];
    }
    return cur->change[index];
  }
  
  void setChar(int index, char c) {
    change[index] = c;
  }

  myString substring(int index1, int index2){
    myString newstr(str, index1, index2-index1+1, this);
    return newstr;
  }
};
//O(1) rumtime
class myString
{
  string str;
  int size;
  int offset;
  unordered_map<int, char> change;
public:
  myString(string str, int offset, int size, unordered_map<int, char> change):str(str),offset(offset), change(change){};
  char charAt(int index){
    if (change.count(index) != 0)
    {
      return change[index];
    } else return str[index];
  }
  
  void setChar(int index, char c) {
    change[index] = c;
  }

  myString substring(int index1, int index2){
    myString newstr(str, index1, index2-index1+1, change);
    return newstr;
  }
};

//voting
//dp[i][j] = dp[i][j-1]*(1-p[i]) + dp[i-1][j-1]*p[i];
//between 1--j, there are i people voting for you
//add dp[251][500] + ....dp[500][500] 