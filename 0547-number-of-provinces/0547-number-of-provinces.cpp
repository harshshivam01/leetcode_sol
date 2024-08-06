class Solution {
public:
     void dfs(vector<vector<int>>& isConnected,int i,vector<int>&visi){
        visi[i]=1;
         for (int j = 0; j < isConnected.size(); ++j) {
           if(visi[j]==0&&isConnected[i][j]==1){
            dfs(isConnected,j,visi);
           }
        }
     }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n =isConnected.size();
         int m =isConnected[0].size();
        // vector<int>adj[n];
        // for(int i=0;i<n;i++){
        //   for(int j=0;j<m;j++){
        //     adj[i].push_back(isConnected[i][j]);
        //   }
        // }
        vector<int>visi(n+1,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(visi[i]==0){
             dfs(isConnected,i,visi);
             count++;
            }
        }
        return count;
    }
};