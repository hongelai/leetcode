    int ladderLength(string start, string end, unordered_set<string> &dict) {
        
        if(start == end )return 1;
        deque<string> Q;
        unordered_set<string> visited;
        bool found = false;
        int count = 0, level = 1;

        Q.push_back(start);
        visited.insert(start);

        while(!Q.empty() && level < dict.size()){
            string str = Q.front();
            if(count == 0){
                count = Q.size();
                level++;
            } 
            Q.pop_front();
            count--;

            string next = str; 
            for (int i = 0; i < next.size(); ++i){

                next = str; 
                for (next[i] = 'a'; next[i] <= 'z'; ++next[i]) 
                    if (dict.find(next)!= dict.end() && !visited.count(next)) {
                        Q.push_back(next);
                        visited.insert(next);
                        if(next == end){
                           found = true;
                           break;  
                        } 
                    }        
            }
            if(found) break;
        }

        if(found) return level;
        else return 0;
    }