class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<int> adj[numCourses];
       vector<int>ans;
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
            ans.push_back(x);
           count++;
            for (auto it : adj[x]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
      
    if(count==V)return ans;
    else return {};
    }
};