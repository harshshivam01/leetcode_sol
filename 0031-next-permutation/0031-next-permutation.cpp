class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int br=-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i+1]>nums[i]){
                br=i;
                break;
            }
        }
        if(br>=0){
           for(int i=nums.size()-1;i>br;i--){
            if(nums[i]>nums[br]){
                swap(nums[br],nums[i]);
                break;
            }
           } 
            
        }

        reverse(nums.begin()+br+1,nums.end());

    }
};