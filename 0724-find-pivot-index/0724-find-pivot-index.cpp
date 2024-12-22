class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> leftsum(nums.size(), 0);
        vector<int> rightsum(nums.size(), 0);
        
        // Build the left sum array
        int left = 0;
        for (int i = 0; i < nums.size(); i++) {
            left += nums[i];
            leftsum[i] = left;
        }
        
        // Build the right sum array
        int right = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            right += nums[i];
            rightsum[i] = right;
        }
        
        // Compare leftsum and rightsum to find the pivot index
        for (int i = 0; i < nums.size(); i++) {
            if (leftsum[i] == rightsum[i]) {
                return i;
            }
        }
        
        return -1; // Return -1 if no pivot index is found
    }
};
