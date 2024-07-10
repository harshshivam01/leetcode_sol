class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string>st;
       for(int i=0;i<logs.size();i++){
          if(!st.empty()&&logs[i]=="../"){
            st.pop();
          }
          else if(!st.empty()&&logs[i]=="./"){
            continue;
          }
          else if(!st.empty()&&logs[i]=="x/"){
            while(!st.empty()&&st.top()=="x"){
                st.pop();
            }
          }
          else if(logs[i]!="../"&&logs[i]!="./"&&logs[i]!="x/"){
            st.push(logs[i]);
          }
       } 
        if(st.empty())return 0;
        else
          return st.size();
    }
};