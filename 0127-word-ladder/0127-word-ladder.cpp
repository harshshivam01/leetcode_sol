class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordlist) {
        unordered_set<string>st;
        for(int i=0;i<wordlist.size();i++){
            st.insert(wordlist[i]);
        }
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
           string s=q.front ().first;
           int count=q.front().second;
           q.pop();
           if(s==endWord)return count;
           for(int i=0;i<s.size();i++){
            char orig=s[i];
            for(char ch= 'a';ch<='z';ch++){
                s[i]=ch;
              
              if(st.find(s)!=st.end()){
                st.erase(s);
                q.push({s,count+1});
              }
            }
            s[i]=orig;
           }
        }
return 0;
    }
};