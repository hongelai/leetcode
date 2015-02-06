
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
}