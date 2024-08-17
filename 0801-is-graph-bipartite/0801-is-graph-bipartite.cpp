class Solution {
public:
  bool dfs(vector<int >adj[],vector<int>&col,int colour,int node){
    col[node]=colour;
    for(auto it :adj[node]){
        if(col[it]==-1){
            if(dfs(adj,col,!colour,it)==false)return false ;
        }
        else if(col[it]==colour)return false;
    }
return true;
  }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
                 adj[graph[i][j]].push_back(i);
            }
        }
        vector<int>col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(dfs(adj,col,0,i)==false)return false ;
            }
        }
        return true;

    }
};