class Solution {
public:
    int longestPalindrome(string s) {
        if(s.size()==1){return 1;}
        int oddcount=0;
        unordered_map<char, int>map;
        for(int i=0;i<s.size();i++){
            map[s[i]]++;
            if(map[s[i]]%2==1)oddcount++;
            else oddcount--;
        }
        if(oddcount>1)
           return s.size()-oddcount+1;
        return s.length();   
    }

};