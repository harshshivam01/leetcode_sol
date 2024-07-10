class Solution {
public:
    bool dfs(int i, vector<int>& visi, vector<int>& ans, vector<int> adj[],
             vector<int>& inst) {
        visi[i] = 1;
        inst[i] = 1;
        // stack<int>st;
        // st.push(i);
        for (auto it : adj[i]) {
            if (visi[it] == 0) {

                if (dfs(it, visi, ans, adj, inst) == false)
                    return false;

            } else if (inst[it] == 1) {
                return false;
            }
        }
        inst[i]=0;
        ans.push_back(i);
        return true;
        // st.push(i);
        // while(!st.empty()){
        //     ans.push_back(st.top());
        //     st.pop();
        // }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // code here
        vector<int> adj[numCourses];

        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }
        vector<int> visi(numCourses, 0);
        vector<int> inst(numCourses, 0);
        vector<int> ans;

        for (int i = 0; i < numCourses; i++) {
            if (visi[i] == 0) {
                if (!dfs(i, visi, ans, adj, inst))
                    return {};
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
