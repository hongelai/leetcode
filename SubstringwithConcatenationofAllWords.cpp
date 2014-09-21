using namespace std;
	int Count(string myString, string str2){
		int count = 0;
		const char *tmp = myString.c_str();
		while(tmp = strstr(tmp, str2.c_str()))
		{
		   count++;
		   tmp++;
		}	
		return count;
	}

    bool isSame(string sub, vector<string> &L){
        int i =0;
        for(; i<L.size();i++){
            if(Count(sub,L[i]) == 1)
                continue;
            else 
                break;
        }
        if(i == L.size())
            return true;
        else return false;
    }
    vector<int> findSubstring(string S, vector<string> &L) {
       size_t word_length = L[0].length();
       size_t v_size = L.size();
       int window_size = v_size*word_length;
       vector<int> result;
       if(S.length() < window_size) return result;
       
       for(int pos = 0; pos < S.length() - window_size; pos++){
           string sub = S.substr(pos,window_size);
           if(isSame(sub,L))
                result.push_back(pos);
       }
    }