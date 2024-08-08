class Solution {
public:
    int check(int x, int y, int m, int n) {
        if (x >= 0 && y >= 0 && x < m && y < n)
            return 1;
        else
            return 0;
    }
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visi, int y, int x,
             int dx[], int dy[]) {
        visi[x][y] = 1;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (check(nx, ny, m, n) == 1 && !visi[nx][ny] &&
                grid[nx][ny] == 1) {
                dfs(grid, visi, ny, nx, dx, dy);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        vector<vector<int>> visi(m, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            if (visi[0][i] == 0 && grid[0][i] == 1) {
                dfs(grid, visi, i, 0, dx, dy);
            }
            if (visi[m - 1][i] == 0 && grid[m - 1][i] == 1) {
                dfs(grid, visi, i, m - 1, dx, dy);
            }
        }
        for (int j = 0; j < m; j++) {
            if (visi[j][0] == 0 && grid[j][0] == 1) {
                dfs(grid, visi, 0, j, dx, dy);
            }
            if (visi[j][n - 1] == 0 && grid[j][n - 1] == 1) {
                dfs(grid, visi, n - 1, j, dx, dy);
            }
        }
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visi[i][j] == 0 && grid[i][j] == 1) {
                    count++;
                }
            }
        }
        return count;
    }
};