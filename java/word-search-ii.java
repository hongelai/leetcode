class Solution {
    public static class TreeNode {
        String word; //preserve the word
        TreeNode[] children = new TreeNode[26];
    }
    
    public static class Trie {
        public TreeNode root;
        
        Trie() {
            root = new TreeNode();
        }
        
        public void insert(String word) {
            TreeNode cur = root;
            
            for (int i = 0; i < word.length(); i++) {
                int c = word.charAt(i) - 'a';
                
                if (cur.children[c] == null) {
                    cur.children[c] = new TreeNode();
                }
                cur = cur.children[c];
            }
            cur.word = word;
        }
    }
    
    public List<String> findWords(char[][] board, String[] words) {
        List<String> res = new ArrayList<>();
        boolean[][] visit = new boolean[board.length][board[0].length];
        Trie tree = new Trie();
        
        if (board.length == 0 || board[0].length == 0 || words.length == 0) return res;
        
        for (String word : words) {
            tree.insert(word);
        }
        
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                int c = board[i][j] - 'a';
                
                if (tree.root.children[c] != null ) {
                    search(board, visit, res, tree.root.children[board[i][j] - 'a'], i, j);
                }
            }
        }
        
        return res;
    }
    
    public void search(char[][]board, boolean[][] visit, List<String> res, TreeNode root, int i, int j) {
        if (root.word != null) {
            res.add(root.word);
            root.word = null; // dedupe
        }
        
        int[] di = {0, 1, 0, -1};
        int[] dj = {1, 0, -1, 0};
        visit[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int x = i + di[k];
            int y = j + dj[k];
            
            if (x >= 0 && x < board.length 
                && y >= 0 && y < board[0].length 
                && !visit[x][y] && root.children[board[x][y] - 'a'] != null) {
                
                
                search(board, visit, res, root.children[board[x][y] - 'a'], x, y);
              
            }
        }
        visit[i][j] = false;
    }
}
