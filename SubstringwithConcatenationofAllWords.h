class Solution {
private:
    int word_length;
public:
    bool isSame(string sub, unordered_map<string,int> word_count,int word_num){
        
        for (int i =0; i< sub.length(); i+= word_length)
        {
            string str = sub.substr(i,word_length);
            unordered_map<string,int>::iterator it = word_count.find(str);
            if(it != word_count.end() && it->second > 0){
                it->second--;
                word_num--;
            }else return false;
        }
        if (word_num == 0)
          return true;
        else
          return false;
    }
    vector<int> findSubstring(string S, vector<string> &L) {
       word_length = L[0].length();
       int v_size = L.size();
       typedef unordered_map<string,int> stringMap;
       int window_size = v_size*word_length;
       vector<int> result;
       
       if(S.length() < window_size) return result;
       
       stringMap word_count;
       for(int i = 0; i<L.size();i++)
          if (word_count.count(L[i])==0)
            word_count[L[i]] = 1;
          else
            word_count[L[i]]++;
          
       for(int pos = 0; pos <= S.length() - window_size; pos++){
           string sub = S.substr(pos,window_size);
           if(isSame(sub,word_count,L.size())){
              result.push_back(pos);
           }
                
       }
       return result;
    }
};