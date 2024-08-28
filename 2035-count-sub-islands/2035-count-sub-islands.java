class Solution {
    public int countSubIslands(int[][] grid1, int[][] grid2) {
        int n=grid1.length;
        int m=grid1[0].length;

        int island=0;
        boolean[] isIsland=new boolean[1];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1){
                    isIsland[0]=true;
                    dfs(grid1, grid2, i, j, n, m, isIsland);

                    if(isIsland[0]) island++;
                }
            }
        }
        return island;
    }

    public void dfs(int[][] grid1, int[][] grid2, int i, int j, int n, int m, boolean[] isIsland){
        if(i<0 || i>=n || j<0 || j>=m || grid2[i][j]==0) return;

        if(grid1[i][j]!=grid2[i][j]) isIsland[0]=false;

        grid2[i][j]=0;

        dfs(grid1, grid2, i + 1, j, n, m, isIsland);  // Down
        dfs(grid1, grid2, i - 1, j, n, m, isIsland);  // Up
        dfs(grid1, grid2, i, j + 1, n, m, isIsland);  // Right
        dfs(grid1, grid2, i, j - 1, n, m, isIsland);  // Left

    }
}