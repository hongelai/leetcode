class WordDictionary {
    
    private static class TreeNode {
        boolean isWord;
        TreeNode[] children = new TreeNode[26];
    }
    
    private TreeNode root;

    /** Initialize your data structure here. */
    public WordDictionary() {
        root = new TreeNode();
    }
    
    /** Adds a word into the data structure. */
    public void addWord(String word) {
        TreeNode cur = root;
        
        for (int i = 0; i < word.length(); i++) {
            int c = word.charAt(i) - 'a';
            
            if (cur.children[c] == null)
            {
                cur.children[c] = new TreeNode();
            }
            
            cur = cur.children[c];
        }
        cur.isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    public boolean search(String word) {
        return search(root, word.toCharArray(), 0);
    }
    
    private boolean search(TreeNode root, char[] word, int i) {
        if (i == word.length) return root.isWord;
        
        if (word[i] != '.') {
            int c = word[i] - 'a';
            return root.children[c] != null && search(root.children[c], word, i+1);
        }
        
        for (TreeNode node : root.children) {
            if (node != null && search(node, word, i+1)) return true;
        }
        
        return false;
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */
