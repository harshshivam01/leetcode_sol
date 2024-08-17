class Solution {
public:
  bool isconsecutive(vector<int >nums,int l,int r){
    for(int i=l;i<r;i++){
        if(nums[i+1]-nums[i]!=1){
            return false;
        }
    }
    return true;
  }
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n =nums.size();
        int l=0;
        int r=k-1;
        vector<int >ans;
        while(r<n){
           
            if(isconsecutive(nums,l,r)){
             ans.push_back(nums[r]);
            
            }
            else{
                ans.push_back(-1);
            }
            l++;
            r++;
        }
return ans ;
    }
};