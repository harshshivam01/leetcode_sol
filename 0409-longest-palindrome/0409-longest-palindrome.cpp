class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>map;
        for(int i=0;i<s.size();i++){
         map[s[i]]++;
        }
        int count=0;
        bool flag=false;
        for(auto it:map){
         count+=(it.second/2)*2;
         if(it.second%2!=0){
            flag=true;
         }
        }
        if(flag==true)count++;

        return count;
    }
};