class Solution {
public:
    bool findsub(string &s, string &t,int j){
        if(j==s.size()-1)return true;
        findsub(s,t,j+1);
        for(int i=0;i<t.size();i++){
            if(s[j]==t[i]){
                return true;
            }
        }
        return false;
    }
    bool isSubsequence(string s, string t) {
    
       int k=0;
     for(int i=0;i<t.size();i++){
         if(s[k]==t[i]){
            k++;
           
         }
        
       }
       if(k==s.size())return true;
       else return false; 
  
    //  return findsub(s,t,0);
    }
};