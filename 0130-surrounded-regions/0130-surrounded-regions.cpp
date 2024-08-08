class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int m = board.size();
        int n = board[0].size();
        
        queue<pair<int, int>> q;
        
        // Push all 'O's on the boundary into the queue
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') q.push({i, 0});
            if (board[i][n-1] == 'O') q.push({i, n-1});
        }
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') q.push({0, j});
            if (board[m-1][j] == 'O') q.push({m-1, j});
        }
        
        // Directions for moving in 4 ways
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        
        // Mark all 'O's connected to the boundary as safe (change to 'S')
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            board[x][y] = 'S';  // Mark as safe
            
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && board[nx][ny] == 'O') {
                    q.push({nx, ny});
                }
            }
        }
        
        // Change all remaining 'O' to 'X' and 'S' back to 'O'
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'S') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
