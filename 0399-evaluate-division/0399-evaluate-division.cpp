class Solution {
public:
    void dfs(unordered_map<string, vector<pair<string, double>>>& adj, 
             string src, string dest, double& ans, double product, 
             unordered_set<string>& visi) {
        if (visi.find(src) != visi.end()) {
            return;
        }
        visi.insert(src);

        if (src == dest) {
            ans = product;
            return;
        }

        for (auto& p : adj[src]) {
            string v = p.first;
            double val = p.second;
            dfs(adj, v, dest, ans, product * val, visi);
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                 vector<double>& values,
                                 vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map<string, vector<pair<string, double>>> adj;

        // Build adjacency list
        for (int i = 0; i < n; i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];

            adj[u].push_back({v, val});
            adj[v].push_back({u, 1.0 / val});
        }

        vector<double> result;

        // Process each query
        for (auto& query : queries) {
            string src = query[0];
            string dest = query[1];

            double ans = -1.0;
            double product = 1.0;

            if (adj.find(src) != adj.end() && adj.find(dest) != adj.end()) {
                unordered_set<string> visi;
                dfs(adj, src, dest, ans, product, visi);
            }

            result.push_back(ans);
        }

        return result;
    }
};
