class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int an=*max_element(nums.begin(),nums.end());
        int p;
        int n=nums.size();
        // for(int i=0;i<n-1;i++){
        //  p= (nums[i]&nums[i+1]);
        //     an=max(p,an);

        // }
        cout<<an;
        int maxi=0;
        int count=0;
        for(int i=0;i<n;i++){
            
            if(nums[i]==an){
                count++;
                maxi=max(count,maxi);
            }
            else{
                
                // maxi=max(count,maxi);
                count=0;
            }
        }
        return maxi;;
    }
};