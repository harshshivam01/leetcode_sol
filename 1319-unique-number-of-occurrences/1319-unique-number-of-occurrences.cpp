class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
   unordered_map<int,int>mp;
      for(int i=0;i<arr.size();i++){
        mp[arr[i]]++;
      }
      vector<int>m(arr.size()+1,0);
      for(auto it :mp){
        m[it.second]++;
      }
       for(auto it :m){
        if(it>1)return false;
       }
      return true;
    }
};