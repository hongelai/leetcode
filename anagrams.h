    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        if(strs.size() == 0) return res;
        unordered_map<string,vector<string> > um;
        for(auto& s: strs){
            string key =s;
            sort(key.begin(),key.end());
            um[key].push_back(s);  //unordered_multimap不能用下标访问，他没有重载【】，因为它的下表可以重复
        }
        for(auto it = um.begin(); it != um.end(); it++){
            if((it->second).size() > 1) res.insert(res.end(),(it->second).begin(),(it->second).end());
        }
    }