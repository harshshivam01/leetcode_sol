class Solution {
public:
    
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
    //     for(int i=0;i<nums.size();i++){
            
    //     }
    while(k>0){
        int mini=*min_element(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]==mini){
                nums[i]=nums[i]*multiplier;
                break;
            }
            
        }
        k--;
    }
    return nums;
    }
};