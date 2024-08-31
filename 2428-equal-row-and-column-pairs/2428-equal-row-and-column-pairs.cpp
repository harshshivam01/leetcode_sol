class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        int m =grid[0].size();
        int ans=0;
        map<vector<int>,int>mp1;
        map<vector<int>,int>mp2;
        for(int i=0;i<n;i++){
            vector<int>v;
            for(int j=0;j<n;j++){
              v.push_back(grid[i][j]);

            }
            mp1[v]++;
        }
        
         for(int i=0;i<n;i++){
            vector<int>v;
            for(int j=0;j<n;j++){
              v.push_back(grid[j][i]);

            }
            mp2[v]++;
        }
    for(auto it:mp1){
        if(mp2.find(it.first)!=mp2.end()){
            ans+=(it.second*mp2[it.first]);
        }
    }
      return ans ;  
    }
};