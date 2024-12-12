class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<arr1.size();i++){
            mp[arr1[i]]++;
        }
        for(int i=0;i<arr2.size();i++){
            while(mp[arr2[i]]>0){
                ans.push_back(arr2[i]);
                mp[arr2[i]]--;
            }
        }
        vector<int>temp;
        for(auto it:mp){

            int k=it.second;

           while(k--){
            temp.push_back(it.first);
            
           }
        }
        sort(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++){
            ans.push_back(temp[i]);
        }
        return ans ;
    }
};