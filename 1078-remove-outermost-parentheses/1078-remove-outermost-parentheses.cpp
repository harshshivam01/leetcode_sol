class Solution {
public:
    string removeOuterParentheses(string s) {
        string res="";
        int count=0;
        int size=s.size();
        // for(int i=0;i<size;i++){
        //     if(s[i]=='(')
        //         count++;
        //     else
        //         count--;
                
        //     if((count==1 && s[i]=='(') || (count==0 && s[i]==')')) 
        //         continue;
        //     else
        //         res+=s[i];
        // }
        stack<char >st;
       
      
        for(int i=0;i<size;i++){
            char ch=s[i];
          if(ch=='('){
            if(st.size()>0)
            res+=ch;
            st.push(ch);
          } else{
                if(st.size()>1){
                    res +=')';
                }
                st.pop();
            }
        }
      
        return res;
    }
};