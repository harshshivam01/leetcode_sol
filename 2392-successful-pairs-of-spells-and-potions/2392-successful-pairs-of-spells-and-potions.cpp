class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        int m=potions.size();
        sort(potions.begin(),potions.end());
        vector<int >ans;
        int i=0;
        while(i<n){
            long long spell=spells[i];
            long long temp =0;
            int low=0,high=m-1;
            while(low<=high){
                int mid= (low+high)/2;
                long long ch=potions[mid]*spell;
                if(ch>=success){
                    temp=m-mid;
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            
            }
            ans.push_back(temp);
            i++;
            
        }

        return ans;
    }
};