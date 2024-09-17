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
        int x = entrance[0];
        int y = entrance[1];
        queue<pair<int, int>> q;
        q.push({x, y});
        maze[x][y] = '+';
        int step = 0;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int p = q.front().first;
                int r = q.front().second;
                q.pop();
                if (p == 0 || r == 0 || p == m - 1 || r == n - 1) {
                    if (p != entrance[0] || r != entrance[1]) {
                        return step;
                    }
                }
                for (int j = 0; j < 4; j++) {
                    int nx = p + dx[j];
                    int ny = r + dy[j];
                    if (check(nx, ny, m, n)==true && maze[nx][ny] == '.') {
                        maze[nx][ny] = '+';
                        q.push({nx, ny});
                    }
                }
            }
            step++;
        }
        return -1;
    }
};