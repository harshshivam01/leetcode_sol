class Solution {
public:
    int findmax(vector<int>&piles){
        int maxi=INT_MIN;
        for(int i=0;i<piles.size();i++){
            maxi=max(maxi,piles[i]);
        }
        return maxi;
    }
    long long calcHr(vector<int>piles,int k){
        long long h=0;
        for(int pile :piles){
  int hoursToEatPile = ceil(pile / (double)k);
  h +=hoursToEatPile;


        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
      int left=1;
       int right=findmax(piles);
        int ans=-1;
        while(left<=right){
        int mid = left + (right - left) / 2;

            long long th=calcHr(piles,mid);
            if(th<=h){
                 ans=mid;
                 right=mid-1;
            }
            else{
              left=mid+1;
            }
        }
         return ans;
    }
};