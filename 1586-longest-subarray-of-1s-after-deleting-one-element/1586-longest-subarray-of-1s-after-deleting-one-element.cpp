class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int maxi = 0;
       
        int count0 = 0;
        while(j<nums.size()){
             if(nums[j]==0)count0++;
            while( count0 > 1) {
                if(nums[i] == 0) {
                   
                    count0--;
                }
                 i++;
            }
           
           
           
            maxi = max(maxi, j-i);
            j++;
        }

        return maxi;
    }
};