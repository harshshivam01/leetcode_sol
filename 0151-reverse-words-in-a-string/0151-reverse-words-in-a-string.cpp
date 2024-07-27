class Solution {
public:
    string reverseWords(string s) {
        string str = "";
        stack<string> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if(!str.empty()){
                     st.push(str);
                str = "";
                }
               
            } else
                str += s[i];
        }
        if (!str.empty()) { // Push the last word if there is any
        st.push(str);
    }
        string ans = "";
        while (st.size()!=1) {
           
           
                ans+=st.top()+" ";
                st.pop();
            
           
        }
         ans+=st.top();
        return ans ;
    }
};