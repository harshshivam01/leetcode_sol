class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
        vector<int> adj[n];
        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }
        vector<int> ans;
        int count = 0;
        int m = queries.size();
        for (int i = 0; i < m; i++) {
            adj[queries[i][0]].push_back(queries[i][1]);
            vector<bool> visited(n, false);
            queue<pair<int, int>> q;
            q.push({0, 0});

            while (!q.empty()) {
                int x = q.front().first;
                int dista = q.front().second;

                q.pop();
                if (x == n - 1) {
                    ans.push_back(dista);
                    break;
                }
                for (auto it : adj[x]) {
                    if (visited[it] == false) {
                        visited[it] = true;
                        q.push({it, dista + 1});
                    }
                }
            }
        }
        return ans;
    }
};