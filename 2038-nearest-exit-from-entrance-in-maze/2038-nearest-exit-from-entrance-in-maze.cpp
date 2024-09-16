class Solution {
public:
    bool check(int x, int y, int m, int n) {
        if (x >= 0 && y >= 0 && x < m && y < n) {
            return true;
        }
        return false;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        int ans = 0;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        queue<pair<int, int>> q;
        int p = entrance[0];
        int r = entrance[1];
        maze[p][r] = '+';

        q.push({p, r});

        while (!q.empty()) {
            int size = q.size();
            for (int j = 0; j < size; j++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if ((x == 0 || y == 0 || x == m - 1 || y == n - 1)) {
                    if ((x != entrance[0] or y != entrance[1]))
                        return ans;
                }

                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (check(nx, ny, m, n)==1 && maze[nx][ny] == '.') {
                        maze[nx][ny] = '+';
                        q.push({nx, ny});
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};