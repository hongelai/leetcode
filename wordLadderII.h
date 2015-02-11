  //用两个set分别存当前层和下一层，不断轮换，每访问一层就先visit掉这一层
  //若当前层发现了end则进行回溯打印，不在访问下去
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        unordered_set<string> cur, next;
        unordered_set<string> visited;
        unordered_map<string, vector<string> > parent;
        vector<vector<string> > res;
        cur.insert(start);
        dict.insert(end);
        
        while(!cur.empty()){
          if (cur.count(end) != 0) {
              vector<string> path;
              gen_path(parent, path, start, end, res); 
              break;
          }
          for (const auto& node : cur) visited.insert(node);
          for (const auto& node : cur) {
              
              for (int i = 0; i < node.length(); i++) {
                  string tmp = node;
                  for (char j = 'a'; j <= 'z'; j++) {
                      tmp[i] = j;
                      if (!visited.count(tmp) && (dict.find(tmp) != dict.end())) {
                          next.insert(tmp);
                          parent[tmp].push_back(node);
                      }
                  }
                  
              }
          }
          cur.clear();
          swap(cur, next);
        }
        return res;
    }
    void gen_path(unordered_map<string, vector<string> > &father, vector<string> &path, const string &start, const string &word,
              vector<vector<string> > &result) {
          path.push_back(word);
          if (word == start) {
              result.push_back(path);
              reverse(result.back().begin(), result.back().end());
          } else {
              for (int i = 0; i < father[word].size(); ++i) {
                  gen_path(father, path, start, father[word][i], result);
              }
          }
          path.pop_back();
      }