class Solution {
public:
    int numberOfSubstrings(string s) {
      int l=0;int r=0;
      int ans=0;
      unordered_map<char,int>map;
      while(r<s.size()){
          map[s[r]]++;
          while(map['a']>0&&map['b']>0&&map['c']>0&&l<=r){
                 map[s[l]]--;
                 ans+=(s.size()-r);
                 l++;
          }
          r++;
      }
      return ans;
    }
};