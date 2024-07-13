class Solution {
public:
    int dp[110];
    int dp1[110];
    int f1(vector<int>& nums, int n) {
        if (n < 0) {
            return 0;
        }
        if(dp[n]!=-1)return dp[n];
        return dp[n]= max(f1(nums, n - 2) + nums[n], f1(nums, n - 1));
    }
    int f(vector<int>& nums, int n) {

        if (n < 1) {
            return 0;
        }
        if(dp1[n]!=-1)return dp1[n];
        return dp1[n]=max(f(nums, n - 2) + nums[n], f(nums, n - 1));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
       memset(dp ,-1,sizeof(dp));
       memset(dp1 ,-1,sizeof(dp1));
        // if (nums[n-1]>nums[0]) {
        //     return f(nums, n - 1);
        // } else if(nums[n-1]<nums[0]) {
        //     return f1(nums, nums.size() - 2);
        // }
        // else{
            return max( f(nums, n - 1),f1(nums, nums.size() - 2));
        // }
    }
};