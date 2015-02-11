
//先排序，然后左右夹逼 求得目标值
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        multimap<int,int> map;//multimap will sort element
        for(auto it = numbers.begin(); it != numbers.end(); it++){
            map.insert(make_pair(*it,it-numbers.begin()));
        }
        
        auto post = map.end();
        post--;
        for(auto pre = map.begin();pre!= post;){
            if(pre->first+post->first > target) post--;
            else if(pre->first+ post->first < target) pre++;
            else{
                if(pre->second > post->second){
                    res.push_back(post->second+1);
                    res.push_back(pre->second+1);
                }else{
                    res.push_back(pre->second+1);
                    res.push_back(post->second+1);
                }
                break;
            }
        }
        return res;
    }

    //跟暴力解法差不多 ，但是利用了hashmap的线性查找时间的特性使得为O(n)
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        unordered_multimap<int,int> map;
        for(auto it = numbers.begin(); it != numbers.end(); it++){
            int second = target  - *it;
            auto pos = map.find(second);
            if(pos == map.end())
                map.insert(make_pair(*it,it-numbers.begin()));
            else{
                res.push_back(pos->second+1);
                res.push_back(it-numbers.begin()+1);
            }
        }

        return res;
    }