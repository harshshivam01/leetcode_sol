class Solution {
public:
    int triangularSum(vector<int>& nums) {
       vector<int>temp(nums.size()-1);
        if (nums.size() == 1) {
            return nums[0];
        }

        for (int i = 0; i < nums.size()-1; i++) {

            int x = (nums[i] + nums[i + 1])%10;
            temp[i] = x;


        }
        nums=temp;

      return  triangularSum(nums);
    }
};