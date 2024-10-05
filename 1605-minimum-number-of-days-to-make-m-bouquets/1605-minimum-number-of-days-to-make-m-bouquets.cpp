class Solution {
public:
  bool check(vector<int>&bloomDay,int m ,int k,int mid ){
    int count=0; int noboque=0;
    for(int i=0;i<bloomDay.size();i++){
        if(bloomDay[i]<=mid){
          count++;
    }
        else{
            noboque+=count/k;
            count=0;
        }
    }
    noboque+=count/k;
    if(noboque>=m){
        return true;
    }else{
        return false ;
    }
  }
    int minDays(vector<int>& bloomDay, int m, int k) {
         int right=*max_element(bloomDay.begin(),bloomDay.end());
         int left=1;
         long long int s= m * 1ll * k ;
         if(s>bloomDay.size())return -1;
         while(left<=right){
            int mid=left+(right-left)/2;
           bool isdone= check(bloomDay,m,k,mid);
           if(isdone==true){
            right=mid-1;
           }
           else{
            left=mid+1;
           }
         }
return left;
    }
};