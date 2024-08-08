class Solution {
public:
    int check(int x, int y, int m, int n) {
        if (x < m && y < n && x >= 0 && y >= 0)
            return 1;
        else
            return 0;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int days = 0;
        int cnt = 0;
        int total = 0;

        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0)
                    total++;
                if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        while (!q.empty()) {
            int k = q.size();
            cnt += k;

            while (k--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int newx = x + dx[i];
                    int newy = y + dy[i];
                    if (check(newx, newy, m, n) == 1 && grid[newx][newy] == 1) {
                        grid[newx][newy] = 2;
                        q.push({newx, newy});
                    }
                }
            }
            if (!q.empty())
                days++;
        }

        return total == cnt ? days : -1;
    }
};