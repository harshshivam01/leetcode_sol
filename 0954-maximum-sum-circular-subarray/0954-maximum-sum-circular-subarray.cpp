int kad(vector<int>&nums){
     int maxsum=INT_MIN;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
             sum=sum+nums[i];
            maxsum= max(sum,maxsum);
            if(sum<0){
                sum=0;
            }
        }
        return maxsum;
}
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxsum=kad(nums);
        int normalsum=0;
        int neg=0;
        for(int i=0;i<nums.size();i++){
            normalsum+=nums[i];
           
        }
        
        for(int i=0;i<nums.size();i++){
            nums[i]=-1*nums[i];
        }
       
        int minsum=kad(nums);
        
        if(normalsum+minsum==0){
            return maxsum;
        }
        return max(maxsum,normalsum+minsum);
    }
};