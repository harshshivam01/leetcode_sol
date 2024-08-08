class Solution {
public:
    int check(int x, int y, int m, int n) {
        if (x >= 0 && y >= 0 && x < m && y < n)
            return 1;
        else
            return 0;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!q.empty()) {

            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (check(nx, ny, m, n) == 1 && ans[nx][ny] > ans[x][y] + 1) {
                    ans[nx][ny] = ans[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return ans;
    }
};