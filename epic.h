
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
		for (int i = 0; i < n; i++) {
			sum += A[i] == 0 ? -1 : A[i];
			dp [i] = sum;
			umap[sum].push_back(i);
			if (sum == 0) { // 从0开始的子数组
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
			res = max(res, maxIndex - minIndex);
			iter++;
		}
		return res;
	}

