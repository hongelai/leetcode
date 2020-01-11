class Solution {
    int[] xt = new int[]{1, 0 , -1, 0};
    int[] yt = new int[]{0, 1, 0, -1};
    Set<String> shape = new HashSet<>();

    public int numDistinctIslands(int[][] grid) {
        for (int i = 0; i < grid[0].length; i++) {
            for (int j = 0; j < grid.length; j++) {
                if (grid[j][i] == 1) {
                    StringBuilder hash = new StringBuilder("");
                    dfs(grid, i, j, hash);
                    shape.add(hash.toString());
                }
            }
        }
        return shape.size();
    }

    //use 0 - 7 to represent all possible neibor condition, four direction with 0/1
    public void dfs(int[][] grid, int x, int y, StringBuilder hash) {
        for (int i = 0; i <= 3; i++) {
            int xx = x + xt[i];
            int yy = y + yt[i];
            if (xx >= 0 && xx < grid[0].length
                    && yy >= 0 && yy < grid.length
                    && grid[yy][xx] == 1 ) {
                hash.append(i);
                grid[yy][xx] = 0;
                dfs(grid, xx, yy, hash);
            } else {
                hash.append(i + 4);
            }
        }
    }
}