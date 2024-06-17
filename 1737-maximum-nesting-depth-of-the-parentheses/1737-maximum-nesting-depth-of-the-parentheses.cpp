class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        
        int cnt=0;
        
        for(int i=0;i<s.size();i++){
           
          if(s[i]=='('){
            st.push(s[i]);
        
          }
          else if(s[i]==')'){
            cnt=max(cnt,static_cast<int>(st.size()));
            st.pop();
           
          }
         
          
        }
        return cnt;
    }
};