class Solution {
public:
  long long dp[205][205];
  long long f(int i,int j,int m,int n, vector<vector<int>>& grid){
    if(i==m-1&&j==n-1)return grid[i][j];
    if(dp[i][j]!=-1)return dp[i][j];
    int pick=INT_MAX;
    int notpick=INT_MAX;
    if(i+1<m){
    pick=f(i+1,j,m,n,grid);
    }if(j+1<n){
 notpick=f(i,j+1,m,n,grid);
    }
   
    return dp[i][j]=grid[i][j]+min(pick,notpick);
  }
    int minPathSum(vector<vector<int>>& grid) {
       memset(dp,-1,sizeof(dp));
       int m=grid.size();
       int n=grid[0].size();
       return  f(0,0,m,n,grid);
    }
};