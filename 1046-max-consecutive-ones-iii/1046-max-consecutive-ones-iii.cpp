class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        int j = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                cnt++;

            while (cnt > k) {
                if (nums[j] == 0) {
                    cnt--;
                }

                j++;
            }

            maxi = max(i - j + 1, maxi);
        }
        return maxi;
    }
};