class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
    
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
        queue<tuple<int, int, int>> q;
        set<tuple<int, int, int>> visited;
    
        q.push({0, 0, health});
        visited.insert({0, 0, health});
    
        while (!q.empty()) {
            auto [x, y, current_health] = q.front();
            q.pop();
            
            // Decrease health if the current cell is 1
            if (grid[x][y] == 1) {
                current_health--;
            }
            
            // Check if health became 0 or negative
            if (current_health <= 0) {
                continue;
            }
            
            // Check if the current position is the bottom-right cell
            if (x == m - 1 && y == n - 1) {
                return true;
            }
        
            for (auto& dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;
                
                if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                    if (visited.find({nx, ny, current_health}) == visited.end()) {
                        q.push({nx, ny, current_health});
                        visited.insert({nx, ny, current_health});
                    }
                }
            }
        }
    
        return false;
    }
};