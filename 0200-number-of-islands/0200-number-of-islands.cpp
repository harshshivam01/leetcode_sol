class Solution {
public:
    //   void bfs(vector<vector<char>>& grid,vector<int>&visi,int start){
    //     visi[start]=1;
    //     queue<int>q;
    //     q.push(start);
    // while(!q.empty()){
    //     int node=q.front();
    //     q.pop();
    //     for(int i=0;i<grid.size();i++){
    //         if(grid[node][i]==1&&visi[i]==0){
    //             visi[i]=1;
    //             q.push(i);
    //         }
    //     }
    // }
    //   }
    bool check(int newx, int newy, int n, int m) {
        return (newx >= 0 && newy >= 0 && newx < n && newy < m);
    }
    void bfs(int x, int y, vector<vector<char>>& grid, vector<vector<int>>& visi, int n, int m) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visi[x][y] = 1;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    while (!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newx = curx + dx[i];
            int newy = cury + dy[i];

            if (check(newx, newy, n, m) && !visi[newx][newy] && grid[newx][newy] == '1') {
                visi[newx][newy] = 1;
                q.push({newx, newy});
            }
        }
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> visi(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && visi[i][j] == 0) {
                    bfs(i, j, grid, visi, n, m);
                    count++;
                }
            }
        }
        // int dx[4] = {0, 0, 1, -1};
        // int dy[4] = {1, -1, 0, 0};
        // while (!q.empty()) {
        //     int x = q.front().first;
        //     int y = q.front().second;
        //     q.pop();
        //     for (int i = 0; i < 4; i++) {
        //         int newx = x + dx[i];
        //         int newy = y + dy[i];

        //         if (check(newx, newy, n, m) && visi[newx][newy] == 0 &&
        //             grid[newx][newy] == '1') {
        //             visi[newx][newy] = 1;
        //             q.push({newx, newy});
                    
        //         }
        //     }
           
        // }

        return count;
    }
};