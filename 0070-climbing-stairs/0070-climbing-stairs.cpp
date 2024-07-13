class Solution {
public:
  int f(int n,vector<int >&dp){
    if(n==1)return 1;
    if(n==2)return 2;
    if(dp[n]!=-1)return dp[n];
    return dp[n]=f(n-1,dp)+f(n-2,dp);
  }

    int climbStairs(int n) {
        // if(n==1){
        //     return 1;
        // }
        // else if(n==2){
        //     return 2;
        // }
       
        // return climbStairs(n-1)+climbStairs(n-2);
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
};