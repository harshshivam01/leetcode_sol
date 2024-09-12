class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count=0;
         int n=allowed.size();

        unordered_set<char>mp(allowed.begin(),allowed.end());
        for(int i=0;i<words.size();i++){
            string s=words[i];
           
            bool flag=true;
          
                for(int j=0;j<s.size();j++){
                    if(mp.find(s[j])==mp.end())flag=false;
                   
                }
            
            if(flag==true)count++;

        }
        return count;
    }
};