struct cacheNode{
  int key;
  int value;
  cacheNode(int k, int v) : key(k), value(v) {}
};
class LRUCache{
public:
    LRUCache(int capacity):size(capacity) {}
    
    int get(int key) {
        if (map.find(key) != map.end()) {
            cacheList.splice(cacheList.begin(), cacheList, map[key]);// move to head
            map[key] = cacheList.begin();
            return map[key]->value;
        } else {
            return -1;
        }
    }
    
    void set(int key, int value) {
        if (map.find(key) != map.end()) {
            cacheList.splice(cacheList.begin(), cacheList, map[key]);
            map[key] = cacheList.begin();
            cacheList.begin()->value = value; //iterator use -> to access
        } else {
            if (cacheList.size() == size) {
                map.erase(cacheList.back().key); //back() return the reference so the cacheNode
                cacheList.pop_back();
            }
            cacheNode newNode(key, value);
            cacheList.push_front(newNode);
            map[key] = cacheList.begin();
        }
    }
    list<cacheNode> cacheList;
    unordered_map<int, list<cacheNode>::iterator> map; //key address pair
    int size;
};