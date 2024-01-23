class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
     vector<int>hash(n+1,0);
      int missing;
      int repeating;
      for(int i=0;i<nums.size();i++){
          hash[nums[i]]++;
      }
      for(int i=1;i<n+1;i++){
          if(hash[i]>=2){
             repeating=i;
          }
          else if(hash[i]==0){
             missing=i;
          }
      }
      return {repeating,missing};
    }
};