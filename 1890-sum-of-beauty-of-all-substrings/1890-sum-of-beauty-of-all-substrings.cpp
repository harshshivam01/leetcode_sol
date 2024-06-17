class Solution {
public:
    int beautySum(string s) {
       
        int sum=0;
      for(int k=0;k<s.size();k++){
         unordered_map<char,int>mp;
      
        for(int i=k;i<s.size();i++){
            mp[s[i]]++;
           int maxi=0;int mini=INT_MAX;
           for(auto it :mp){
            maxi=max(maxi,it.second);
            mini=min(mini,it.second);
           }
             sum+=(maxi-mini); 
            }
            }
    return sum;
    }
};