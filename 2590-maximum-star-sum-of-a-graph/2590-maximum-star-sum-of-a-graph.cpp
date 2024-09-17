class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        vector<vector<int>> adj(vals.size());
       
        int maxsum = INT_MIN;
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        for (int i = 0; i < vals.size(); i++) {
            int sum = vals[i];
            priority_queue<int> pq;
           
            for (auto it : adj[i]) {
                pq.push(vals[it]);
            }
            int  x=k;
            while (!pq.empty()&&x > 0) {
                if(pq.top()<0)break;
                sum += pq.top();
                pq.pop();
                x--;
            }
         
            maxsum = max(maxsum, sum);
        }
        return maxsum;
    }
};