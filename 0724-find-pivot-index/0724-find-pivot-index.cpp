class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> leftsum(nums.size(),0);
        vector<int> rightsum(nums.size(),0);
        int left = 0;
        int right = 0;
        for (int i = 0; i < nums.size(); i++) {
            left+=nums[i];
            leftsum[i]=left;
        }
         for (int i = nums.size()-1; i >=0; i--) {
            right+=nums[i];
            rightsum[i]=right;
        }
        left=0;
        
     for(int i=0;i<leftsum.size();i++){
        if(leftsum[i]==rightsum[i]){
            return i;
        }
     }
        return -1;
    }
};