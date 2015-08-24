    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<char,int> cast{{'A',0},{'C',1},{'G',3},{'T',2}};//map A C G T to 00 01 11 10
        unordered_map<int, int> map;
        vector<string> res;
        int len = s.length();
        if (len < 10) return res;
        int i = 0, init = 0, mask = 0xFFFFF;//get lower 20 (2x*10) bit
        
        while (i < 9) {  //only get to 9, when it reach 10, then we have to put it in the map
            init = (init << 2 & mask) | cast[s[i++]]; //left move 2 digit, mask out the overhead digit, add the new lower two digit
        }
        while (i < len) {
            init = (init << 2 & mask) | cast[s[i++]];
            if(map[init]++ == 1){
                res.push_back(s.substr(i-10,10));
            }
        }
        return res;
    }



    //trie solution
    int buf[1024*1024];
    int cur_button;
    vector<string> result;

    int get_int(char tag){
        switch (tag){
            case 'A': return 0;
            case 'C': return 1;
            case 'G': return 2;
            case 'T': return 3;
            default : return -1;
        }
    }

    char get_char(int tag){
        switch (tag){
            case 0: return 'A';
            case 1: return 'C';
            case 2: return 'G';
            case 3: return 'T';
            default : return '\0';
        }
    }

    void insert(int array[], int offset){
        int cur = 0;
        for(int i=0; i<10; ++i){
            if(buf[cur+array[(i+offset)%10]] == 0){
                buf[cur+array[(i+offset)%10]] = cur_button;
                cur_button +=4;
            }
            cur = buf[cur+array[(i+offset)%10]];
        }
        if(++buf[cur] == 2){
            string ret;
            for(int i=0; i<10; ++i){
                ret += get_char(array[(i+offset)%10]);
            }
            result.push_back(ret);
        }
    }

    vector<string> findRepeatedDnaSequences(string s) {
        memset(buf, 0, sizeof(buf));
        cur_button = 4;
        result.clear();
        if(s.size() < 10) return result;
        int array[10];
        for(int i=0; i<9; ++i){
            array[i] = get_int(s[i]);
        }
        int off_set = 0;
        for(int i=9; i<s.size(); ++i){
            array[i%10] = get_int(s[i]);
            insert(array, off_set);
            off_set = (off_set+1)%10;
        }
        return result;
    }