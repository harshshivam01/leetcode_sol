class Solution {
public:
    int f(vector<int>&nums,int n,vector<int>&dp){
       if(n>nums.size()-1)return 0;
     if(dp[n]!=-1)return dp[n];
       return dp[n]=max(f(nums,n+2,dp)+nums[n],f(nums,n+1,dp));  
    }
    int rob(vector<int>& nums) {
      vector<int>dp(nums.size()+1,-1);
    
     return f(nums,0,dp);
       
    }
};