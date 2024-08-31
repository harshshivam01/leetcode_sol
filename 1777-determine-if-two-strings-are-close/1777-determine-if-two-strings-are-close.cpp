class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int m =word1.size();
        int n=word2.size();
        if(m!=n)return false;
        
        map<char,int>mp1;
       map<char,int >mp2;
       for(auto ch:word1){
        mp1[ch]++;
       }
       for(auto ch:word2){
        mp2[ch]++;
       }
         for(auto ch:word1){
            if(mp1[ch]!=0&&mp2[ch]==0||mp2[ch]!=0&&mp1[ch]==0)return false;
         }
       vector<int>p;
       for(auto it:mp1){
        p.push_back(it.second);
       }
        vector<int>p1;
       for(auto it:mp2){
        p1.push_back(it.second);
       }
       sort(p.begin(),p.end());
       sort(p1.begin(),p1.end());
       
      if(p==p1)return true;
       return false;
    }
};