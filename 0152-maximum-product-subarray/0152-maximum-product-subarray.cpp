class Solution {
public:
    int maxProduct(vector<int>& nums) {
      __int128_t maxp=INT_MIN;
       __int128_t prod=1;
        for(int i=0;i<nums.size();i++){
          prod*=nums[i];

          maxp=max(prod,maxp);
            if(prod==0){
                prod=1;
            }
        }
        prod=1;
        for(int i=nums.size()-1;i>=0;i--){
            prod*=nums[i];

            maxp=max(prod,maxp);
            if(prod==0){
                prod=1;
            }
        }
        return maxp;
    }
};