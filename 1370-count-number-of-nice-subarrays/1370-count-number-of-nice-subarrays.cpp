class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2==0)nums[i]=0;
            else nums[i]=1;
        }
unordered_map<int,int>map;
int sum=0;
int cnt=0;
for(int i=0;i<n;i++){
    sum+=nums[i];
    if(map.find(sum-k)!=map.end()){
        cnt+=map[sum-k];
    }
    if(sum==k)cnt++;
    map[sum]++;
}
    return cnt;    
    }
};