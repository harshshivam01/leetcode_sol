class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int size=nums.size();
        int maxin,minin;
        int maxel=INT_MIN;
        int minel=INT_MAX;
        for(int i=0;i<nums.size();i++){
           if(maxel<nums[i]){
              maxel=nums[i];
              maxin=i;
           }
           if(minel>nums[i]){
            minel=nums[i];
            minin=i;
           }


        }
        cout<<"maxel--"<<maxel<<"minel--"<<minel<<"maxin--"<<maxin<<"minin--"<<minin;
      int front=max(minin,maxin);
      int back=size-min(minin,maxin)-1;
      int both=min(minin,maxin)+size-front;
      return min(front,min(back,both))+1;
    }
};