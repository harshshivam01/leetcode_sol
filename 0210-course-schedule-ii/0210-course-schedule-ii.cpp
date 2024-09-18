class Solution {
public:
    bool dfs(vector<int> adj[], vector<int>& visi, stack<int>& st, int i) {
        if(visi[i]==1)return false;
        if(visi[i]==2)return true;
        visi[i] = 1;
        for (auto it : adj[i]) {
            
               if(dfs(adj,visi,st,it)==false)return false ;
            
        }
        visi[i]=2;
        st.push(i);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> adj[numCourses];
        vector<int> ans;
        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }
        vector<int> visi(numCourses + 1, 0);
        stack<int> st;
        for (int i = 0; i < numCourses; i++) {
            if (visi[i] == 0) {
               if(! dfs(adj, visi, st, i))return {};
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans ;
    }
};