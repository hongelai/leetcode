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