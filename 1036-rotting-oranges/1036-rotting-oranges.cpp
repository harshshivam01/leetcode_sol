class Solution {
public:
    bool check(int newx, int newy, int n, int m) {
        return (newx >= 0 && newy >= 0 && newx < n && newy < m);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        queue<pair<int, int>> q;
        vector<vector<int>> visi(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    visi[i][j] = 1;
                }
            }
        }
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while (!q.empty()) {
            int size = q.size();
            bool changed = false;
            

                for (int k = 0; k < size; k++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int newx = x + dx[i];
                    int newy = y + dy[i];

                    if (check(newx, newy, n, m) && visi[newx][newy] == 0 &&
                        grid[newx][newy] == 1) {
                        visi[newx][newy] = 1;
                        grid[newx][newy] = 2;
                        q.push({newx, newy});
                        changed = true;
                    }
                }
            }
            if (changed) {
                count++;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return count;
    }
};