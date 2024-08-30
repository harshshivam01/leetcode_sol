class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        if(k==1){
            return *max_element(nums.begin(),nums.end());
        }
      
        double sum = 0,maxsum=0;
         while (j < k) {
                sum += nums[j];
                j++;
            }
            maxsum=sum;
        while (j-1 < nums.size()) {
          
            sum+=nums[j++]-nums[i++];
            maxsum=max(maxsum,sum);
        }
        return maxsum/k;
    }
};