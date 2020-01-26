class Trie {
    private static class TreeNode {
        boolean isWord;
        TreeNode[] children = new TreeNode[26];
        
        TreeNode(boolean isWord) {
            this.isWord = isWord;
        }
    }
    
    private TreeNode root;
    
    /** Initialize your data structure here. */
    public Trie() {
        root = new TreeNode(false);
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        TreeNode cur = root;
        
        for (int i = 0; i < word.length(); i++) {
            int c = word.charAt(i) - 'a';
            
            if (cur.children[c] == null) {
                cur.children[c] = new TreeNode(i == word.length() - 1);
            }
            else if (i == word.length() - 1) {
                cur.children[c].isWord = true;
            }
            
            cur = cur.children[c];
        }
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        TreeNode cur = root;
        
        for (int i = 0; i < word.length(); i++) {
            int c = word.charAt(i) - 'a';
            
            if (cur.children[c] == null) return false;
            if (i == word.length() - 1 && !cur.children[c].isWord) return false;
            
            cur = cur.children[c];
        }
        
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        TreeNode cur = root;
        
        for (int i = 0; i < prefix.length(); i++) {
            int c = prefix.charAt(i) - 'a';
            if (cur.children[c] == null) return false;
            
            cur = cur.children[c];
        }
        
        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */