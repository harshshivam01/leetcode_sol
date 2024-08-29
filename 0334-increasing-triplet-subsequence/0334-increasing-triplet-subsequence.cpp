class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int prev1=INT_MAX;
        int prev2=INT_MAX;
        

       for(int i=0;i<nums.size();i++){
            if(nums[i]<=prev1)prev1=nums[i];
            else if(nums[i]<=prev2)prev2=nums[i];
            else return true;
       }
       
        return false;
    }
};