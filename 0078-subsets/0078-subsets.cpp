class Solution {
    vector<vector<int>> ans;

public:
    void helper(int n, vector<int>& nums,  vector<int>& temp ) {
      
        if (n == nums.size()) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[n]);
        helper(n+1,nums,temp);
        
        temp.pop_back();
        helper(n+1,nums,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<int>temp;
        helper(0, nums,temp);
        return ans;
    }
};