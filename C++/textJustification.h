    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> res;
        if(words.empty()) return res;
        size_t size = words.size();
        
        for(int i = 0; i < size; ){
            int j = i, len = 0;
            string str = "";
            for(; j < size; j++){     // calculate word count for one line
                int wLen = words[j].length();
                if(len + wLen + j - i <= L){
                    len += wLen;
                }else{
                    break;
                }
            }
            
            if(j < size){    //not last line
                int sNum = L - len;
                for(int k = i; k < j; k++){
                    str += appendSpace(words[k],k-i,j-i,sNum);
                }
            }else{    //last line
                for(int k = i; k < size; k++){
                    str += words[k];
                    if(k != size - 1) str.append(1,' ');
                    else str.append(L-str.length(), ' ');
                }
            }
            
            res.push_back(str);
            i = j;
        }
        return res;
    }
    string appendSpace(string &str, int index, int wNum, int sNum){
        if(wNum == 1) return str.append(sNum,' '); // one word
        if(index+1 == wNum) return str; //last word
        int remain = sNum%(wNum-1);
        int sLen = index < remain ? sNum/(wNum - 1) + 1 : sNum/(wNum - 1);
        str.append(sLen,' ');
        return str;
    }