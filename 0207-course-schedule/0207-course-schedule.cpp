class Solution {
public:
    bool dfs(int i, vector<int>& visi, vector<int>& pathvisi,
             vector<int> adjList[]) {
        pathvisi[i] = 1;
        visi[i] = 1;
        for (const auto& it : adjList[i]) {
            if (visi[it] == 0) {
                if (dfs(it, visi, pathvisi, adjList))
                    return true;
            } else if (pathvisi[it] == 1)
                return true;
        }
        pathvisi[i] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // int n = prerequisites.size();
        // int m = prerequisites[0].size();
        int V = numCourses;
        vector<int> adj[numCourses];

        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }
        int count = 0;
        queue<int> q;
        vector<int> indegree(V + 1, 0);
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int x = q.front();
            q.pop();
            count++;
            for (auto it : adj[x]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        if (count == V)
            return true;
        else
            return false;
    }
};