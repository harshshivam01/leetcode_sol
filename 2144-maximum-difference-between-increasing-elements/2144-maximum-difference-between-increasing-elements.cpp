class Solution {
public:
    int maximumDifference(vector<int>& nums) {
       int n=nums.size()-1;
        int maxi=nums[n];
        int maxdiff=-1;
        for(int i=n-1;i>=0;i--){
            maxdiff=max(maxdiff,maxi-nums[i]);
            maxi=max(maxi,nums[i]);
        }
        if(maxdiff==0)return -1;
        return maxdiff;

    }
};