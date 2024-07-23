class Solution {
public:
    int dp[100005];
    bool f(vector<int>& nums, int n) {
      
        if(n>=nums.size()-1)return true;
        if (dp[n] != -1)
            return dp[n];
         int i=1;
        while ( i<= nums[n]) {
            if(f(nums, i+ n)){
                return dp[n]=true ;
            }
            i++;
        }

        return  dp[n]=false;
    }
    bool canJump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return f(nums, 0);
    }
};