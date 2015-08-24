class TrieNode {
public:
    // Initialize your data structure here.
    char value;
    map<char, TrieNode*> children;
    bool endNode;
    TrieNode() {}
    TrieNode(char val) {
        endNode = false;
        value = val;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode* cur = root;
        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            if(cur->children.count(c) == 0){
                cur->children[c] = new TrieNode(c);
            }
            cur = cur->children[c];
        }
        cur->endNode = true;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode* cur = root;
        for(int i = 0; i < key.length(); i++){
            char c = key[i];
            if(cur->children.count(c) != 0){
                cur = cur->children[c];
            } else {
                return false;
            }
        }
        return cur->endNode;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(int i = 0; i < prefix.length(); i++){
            char c = prefix[i];
            if(cur->children.count(c) != 0){
                cur = cur->children[c];
            } else {
                return false;
            }
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");