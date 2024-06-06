class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans1;
          int n = nums.size() ;
        sort(nums.begin(), nums.end());
      
        for (int i = 0; i < n; i++) {
           
            if (i != 0 && nums[i] == nums[i - 1])
                continue;

             int j = i + 1;
            int k = n-1;

            while (j < k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> ans = { nums[i], nums[j], nums[k]};
                    ans1.push_back(ans);
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1])j++;
                        
                    while (j < k && nums[k] == nums[k + 1]) k--;
                       
                } 
                else if (nums[i] + nums[j] + nums[k] < 0){
                    j++;
                }
                else{
                    k--;
                }
            }
           
        }
        return ans1;
    }
};