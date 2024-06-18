class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int ,int>mp;
        int cnt=0;
        int sum=0;
        
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mp.find(sum-k)!=mp.end()){
               cnt+=mp[sum-k];
               
            }
            if(sum==k){
                cnt++;
            }
            
                mp[sum]++;
            

        
      
        }
        return cnt;
    }
};