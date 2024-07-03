class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<=4)return  0;
        sort(nums.begin(), nums.end());
         int n = nums.size();
        
        // Evaluate all four possible cases
        int option1 = nums[n-4] - nums[0];       // Remove the three largest elements
        int option2 = nums[n-3] - nums[1];       // Remove the two largest elements and the smallest element
        int option3 = nums[n-2] - nums[2];       // Remove the largest element and the two smallest elements
        int option4 = nums[n-1] - nums[3];       // Remove the three smallest elements
        
        // Return the minimum difference
        return min({option1, option2, option3, option4});
    }
};