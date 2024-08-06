class Solution {
public:
    void dfs(vector<int> adj[], int i, vector<int>& visi) {
        visi[i] = 1;
        for (auto it : adj[i]) {
            if (visi[it] == 0) {
                dfs(adj, it, visi);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        int m = isConnected[0].size();
        vector<int> adj[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isConnected[i][j] == 1 && i != j)
                    adj[i].push_back(j);
            }
        }
        vector<int> visi(n + 1, 0);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (visi[i] == 0) {
                dfs(adj, i, visi);
                count++;
            }
        }
        return count;
    }
};