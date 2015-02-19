
/*******************replcace word in string****************************/
string replace(string s){
	string res = "";
	int len = s.length();
	if(s.empty()) return res;

	int start = 0, end = 0;
	while(end < len){
		while(s[end] != ' ' && s[end] != '\0') end++;
		string sub = s.substr(start, end - start);
		if(sub == "A" || sub == "a"){
			res += sub == "A" ? "The " : "the ";
		}else{
			res += sub + " ";
		}
		start = ++end;
	}
	res.pop_back();
	return res;
}


/*******************well order password****************************/
struct lessthan{
public:
	bool operator() (char a, char b){return tolower(a) < tolower(b);}
}myless;

void dfs(string &item, string &s, int start, int len){
	if(len == 0){
		cout<<item<<endl;
		return;
	}
	for(int i = start; i < s.length(); i++){
		item.insert(item.end(),s[i]);
		dfs(item,s,i+1,len-1);
		item.pop_back();
	}
}

void wellOrder(string s,int len){
	if(s.empty()) return;
	string item = "";
	// function<bool(char,char)> lessthan = [](char a,char b)->bool{return tolower(a) < tolower(b);};
	sort(s.begin(),s.end(),myless);
	dfs(item, s, 0, len);
}

void dfs(string &item, char start, int len){
	if(len == 0){
		cout<<item<<endl;
		return;
	}
	for(char i = start; i < 'Z'; i++){
		item.append(1,i);
		dfs(item,i+1,len-1);
		item.pop_back();
	}
}

void wellOrder(int len){
	if(len == 0) return;
	string item = "";
	// function<bool(char,char)> lessthan = [](char a,char b)->bool{return tolower(a) < tolower(b);};
	
	dfs(item,'A', len);
}
/**********************snake sequence*****************************/
    int SnakeSequence (int[][] matrix){  
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0){  
            return 1;  
        }  
        int m = matrix.size();  
        int n = matrix[0].size();  
        vector<vector<int> > dp(m,vector<int>(n));
        int longest = INT_MIN;  

        for (int i = 0; i < m; i++){  
            for (int j = 0; j < n; j++){  
                dp[i][j] = 1;  
                if (i > 0 && abs(matrix[i-1][j] - matrix[i][j]) == 1) {  
                    dp[i][j] = max(dp[i][j], dp[i-1][j]+1);  
                }  
                if (j > 0 && abs(matrix[i][j-1] - matrix[i][j]) == 1){  
                    dp[i][j] = max(dp[i][j], dp[i][j-1]+1);  
                }  
                longest = max(longest, dp[i][j]);  
            }  
        }  
        return longest;  
    }  

/*************************** max subarray with min length of 2******/
int maxSubarray(vector<int> num){
	int res;
	int sum = 0;
	int start = 0, end = 0;
	while(end < num.size()){
		if(num[end] >  sum + num[end]){
			sum = num[end];
			start = end;
		}else{
			sum += num[end];
		}

		if(end - start >= 2) res = max(res,sum); 
		end++;
	}
	return res;
}

/********************** merge repeating digit in number *******************************/

int mergeNum(int num){
	//11222101应该合并为 12101
	int prev = -1;
	bool negative = num  < 0 ? true : false;
	int res = 0;
	int p = 0;

	num = negative ? num * -1 : num;
	while(num){
		int digit = num%10;
		if (digit != prev)
		{
			res += digit*pow(10,p++);
			prev = digit;
		}
		num /= 10;
	}
	return negative ? -res: res;
}


/************************** adjust mean ***************************************/
int AdjustedMean(vector<int> arr){
	vector<int> three(3,INT_MIN);
	int sum = 0;
	for(int i = 0; i < arr.size(); i++){
		sum += arr[i];
		if(arr[i] >= three[0]){
			three[2] = three[1];
			three[1] = three[0];
			three[0] = arr[i];
		}else if (arr[i] >= three[1])
		{
			three[2] = three[1];
			three[1] = arr[i];
		}else if(arr[i] >= three[2]){
			three[2] = arr[i];
		}
	}
	cout<<three[0]<<" "<<three[1]<<" "<<three[2]<<" "<<sum<<endl;
	int size = arr.size() - 3;
	return (sum - three[0] - three[1] - three[2])/size;
	
}

/************************** phone num letter combination *********************************/
string letterCombination(string s){
	string res = "";
	if(s.empty()) return res;
 	unordered_map<char,vector<char> > map;// should use unordered_map<char, string> map ,more easy to initialize
	char a1[] = {'a', 'b', 'c' };
	char a2[] = {'d','e','f'};
	char a3[] = {'g','h','i'};
	char a4[] = {'j','k'};
	map['1'].assign(a1,a1+3);
	map['2'].assign(a2,a2+3);
	map['3'].assign(a3,a3+3);
	map['#'].assign(a4,a4+2);
	int start = 0, end = 0, len = s.length();

	while(end < len){
		while(s[start] == s[end] && s[end] != '\0') end++;
		int distance = end - start;
		if(s[start] != '#' && s[start] != '0') res.append(1,map[s[start]][distance-1]);
		start = end;
	}

	return res;
}
/******************** show step to anagram *******************************************/
void anagramProcedure(string a, string b){
	int len = a.length();
	for(int i = 0; i < len; i++)
	{
		int pos = b.find(a[i]);
		for(int j = pos; j > i; j--){
			swap(b[j],b[j-1]);
			cout<<b<<endl;
		}
	}
}
/****************** find the longest substring that have the same amount of 0s and 1s **/
	int max01Len(int A[], int n) {
		if (n == 0) {
			return 0;
		}
		vector<int> dp(n, -1);
		unordered_map<int, vector<int>> umap;
		int res = 0;
		int sum = 0;
		for (int i = 0; i < n; i++) { //把0改成-1，如果两个位置的sum是相等的，说明这段距离的0 和 1是相同的
			sum += A[i] == 0 ? -1 : A[i];
			dp [i] = sum;
			umap[sum].push_back(i);
			if (sum == 0) { // 从0开始的子数组，必须包含这种特殊情况用来比较。因为不能从index 位-1 开始算，要是从0开始就是的话，会少算2个。
				res = max(res, i + 1);
			}
		}
		// 对于子数组和相同的多个位置求他们之间的距离
		unordered_map<int, vector<int>>::iterator iter = umap.begin();
		while (iter != umap.end()) {
			if (iter->second.size() <= 1) {
				iter++;
				continue;
			}
			int minIndex = min(iter->second[0], iter->second[1]);
			int maxIndex = max(iter->second[0], iter->second[1]);
			for (int i = 2; i < iter->second.size(); i++) {
				minIndex = min(minIndex, iter->second[i]);
				maxIndex = max(maxIndex, iter->second[i]);
			}
			res = max(res, maxIndex - minIndex);//从minIndex+1 --》 maxIndex是目标区间
			iter++;
		}
		return res;
	}

/****************************print all rect with area A and vetex (x,y)***********************/
    void printAllRect(vector<vector<int> > mt, int x, int y, int a){

    int len = 1;
    int col = mt[0].size();
    int row = mt.size();

    for(int i = len; i <= a; i++){
        if(a%i != 0) continue;
        if (x - i >= 0 && y + a/i < col)
        {
          cout<<"1("<<x-i<<","<<y<<")"<<"("<<x-i<<","<<(y + a/i)<<")"<<"("<<x<<","<<(y+a/i)<<")"<<endl;
        }
        
        if (x + a/i <= row && y + i < col)
        {
          cout<<"2("<<x<<","<<y+i<<")"<<"("<<x+a/i<<","<<(y + i)<<")"<<"("<<x + a/i<<","<<y<<")"<<endl;
        }
        if (x + i <= row && y - a/i >= 0) 
        {
          cout<<"3("<<x+i<<","<<y<<")"<<"("<<x + i<<","<<(y - a/i)<<")"<<"("<<x<<","<<(y - a/i)<<")"<<endl;
        }
        if (x - a/i >= 0 && y - i >= 0) 
        {
          cout<<"4("<<x<<","<<y - i<<")"<<"("<<x-a/i<<","<<(y - i)<<")"<<"("<<x -a/i<<","<<y<<")"<<endl;
        }
    }
}/*************************** battery target ***************************/
int batteryCombination(vector<int> num, int target) {
  if (num.size() == 0 || target == 0)
  {
    return 0;
  }
  vector<int> dp(target + 1);
  dp[0] = 0;
  for (int i = 1; i <= target; ++i)
  {
    dp[i] = INT_MAX;
    for (int j = 0; j < num.size(); ++j)
    {
      if (num[j] <= i && dp[i - num[j]] + 1 < dp[i])
      {
        dp[i] = dp[i - num[j]] + 1;
      }
    }
  }
  return dp[target];
}
/*********************  make exchange         ****************************/
void dfs(vector<vector<float> > &res, vector<float> &entry, float target, vector<float> coin, bool &found) {
    if(target == 0){
      res.push_back(entry);
      for(int i = 0; i < res[res.size() - 1].size(); i++) cout<< res[res.size() - 1][i] << " ";
       cout<<endl;
      found = true;
      return;
    }
    // for(int i = 0; i < res.size(); i++) cout<< res[i] << " ";
    //   cout<<endl;
    for(int i = 0; i < coin.size(); i++) {
      if(!found && coin[i] <= target) {
        cout<<target<<endl;
        entry.push_back(coin[i]);
        dfs(res, entry, target - coin[i], coin, found);
        entry.pop_back();
      }
      // if(found) break;
    }
}
vector<float> exchangeMoney(vector<float> coin, float target) {
    vector<vector<float> > res;
    vector<float> entry;
    if(coin.size() == 0 || target == 0) return entry;
    bool found = false;
    sort(coin.begin(), coin.end(), greater<float>());
    dfs(res, entry, target, coin, found);
    return res[0];
}
//dp solution
int helper(vector<vector<int> > &map, vector<int> &num, int amount, int index){
  if (map[amount][index] > 0) 
  {
    return map[amount][index];
  }
  if(index >= num.size() - 1){
    if(amount%num[index] == 0) return 1;
    else return 0;
  }
  int count = 0;
  for(int i = 0; i * num[index] < amount; i++) {
    count += helper(map, num, amount - i * num[index], index + 1);
  }
  return count;
}
int makeChange(int amount, vector<int> num){
  vector<vector<int> > map(amount + 1, vector<int>(num.size()));
  if (amount == 0 || num.size() == 0)
  {
    return 0;
  }
  return helper(map, num, amount, 0);
}



/***   phone number combination****/
void dfs(unordered_map<char, string> &map, string &entry, string &s, int index){
  if (index == s.length()) {
    cout<<entry<<endl;
    return;
  }
  if (map[s[index]].length() == 0)
  {
    dfs(map, entry, s, index + 1);
  } else {
    for (int i = 0; i < map[s[index]].length(); i++) {
      entry.push_back(map[s[index]][i]);
      dfs(map, entry, s, index + 1);
      entry.pop_back();
    }
  }
}

void phoneNum(string s){
  unordered_map<char, string> map;
  string entry;
  map['9'] = "p";
  map['5'] = "";
  map['1'] = "abc";
  map['2'] = "de";
  dfs(map, entry, s, 0);
}


/**************permutate lower case letter***************/
void dfs(vector<string> &res, string &path, int index, const string &s, 
                          vector<int> &position, vector<char> &letters, vector<bool> used) {
  if (index == position.size())
  {
    res.push_back(path);
    cout<<path<<endl;
    return;
  }
  int lastIndex = -1;
  for (int j = 0; j < letters.size(); ++j)
  {
    if(lastIndex != -1 && letters[lastIndex] == letters[j]) continue;// 同一个位置不允许相同的字母
    if (!used[j] ) 
    {
      lastIndex = j;
      used[j] = true;
      char c = path[position[index]];
      path[position[index]] = letters[j];
      dfs(res, path, index + 1, s, position, letters, used);
      path[position[index]] = c;
      used[j] = false;
    }
  }
}

vector<string> permuteLowerCase(string s){
  vector<string> res; 
  if (s.length() == 0) return res;
  vector<int> position;
  vector<char> letters;
  string path = s;

  for (int i = 0; i < s.length(); ++i)
  {
    if (s[i] <= 'z' && s[i] >= 'a')
    {
      letters.push_back(s[i]);
      position.push_back(i);
    }
  }
  sort(letters.begin(), letters.end());
  vector<bool> used(letters.size(),false);
  dfs(res, path, 0, s, position, letters, used);

  return res;
}

/****output based on vowel****/

vector<string> splitString(string s, unordered_map<char, vector<string> > &map, string &seq) {
  string v = "aeiou";
  vector<string> res;
  int start = 0, end = 0;

  while(end < s.length()) {
      while(s[end] != ' ' && s[end] != '\0') end++;
      string str = s.substr(start, end - start);
      if (str != " " && !str.empty()) {
          res.push_back(str);
          char c = tolower(str[0]);
          if (v.find(c) != string::npos)
          { 
              if (seq.find(c) == string::npos) {
                seq.push_back(c);
              }
              map[c].push_back(str);
          }
      }
      start = end + 1; 
      end = start;
  }

  return res;
}
void outputVowel(string s){
  unordered_map<char, vector<string> > map;
  string v = "aeiou";
  string seq = "";
  vector<string> strs = splitString(s, map, seq);
  
  string newstr = "";
  for (int i = 0; i < seq.length(); ++i)
  {
    for (int j = 0; j < map[seq[i]].size(); ++j)
    {
        newstr += map[seq[i]][j] + " ";
    }
    string remain = "";
    for (int k = 0; k < strs.size(); )
    {
      if (tolower(strs[k][0]) != seq[i])
      {
        remain += strs[k] + " ";
        k++;
      } else {
        strs.erase(strs.begin() + k);
      }
    }

     cout<<newstr + remain<<endl;
  }
}

/********************valid password with broken key******************/
bool isValidPw(string expected, string actual) {
  int i = 0, j = 0;
  char faultKey = '\0';

  for(; i < expected.length() && j < actual.length(); i++) {
    if (expected[i] == actual[j])
    {
      if (faultKey != '\0' && actual[i] == faultKey)
      {
        return false;
      }
      j++;
    } else {
      if (faultKey == '\0')
      {
          faultKey = expected[i];
      } else {
          if (expected[i] != faultKey) return false;
      }
    }
  }
  while(i < expected.length() && expected[i] == faultKey) ++i;
  return (i == expected.length() && j == actual.length()) ? true : false; 
}
/*************cut word that is even and longer than 4*************************/
string seperateWord(string s) {
  int start = 0, end = 0;

  while(end < s.length()) {
    while(s[start] == ' ' && start < s.length()) start++;
    end = start;
    while(end < s.length() && isalpha(s[end])) end++;
    if (end - start >= 4 && (end - start)%2 == 0)
    {
        cout<<"int"<<endl;
      int mid = (start + end) / 2;
      s.insert(mid, 1, ' ');
    } 
    start = end + 1;
  }
  return s;
}