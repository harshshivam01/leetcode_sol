class Solution {
public:
    int maxProduct(vector<int>& nums) {
        __int128_t maxi=INT_MIN;
      __int128_t pre=1;__int128_t suff=1;
        int n =nums.size();
        for(int i=0;i<nums.size();i++){
            if(pre==0)pre=1;
            if(suff==0)suff=1;
            pre=pre*nums[i];
            suff=suff*nums[n-i-1];
            maxi=max(maxi,max(pre,suff));
        }
        return  maxi ;
    }
};