class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> st;
        int maxpoint = 0;

        if (x >= y) {
            for (int i = 0; i < s.size(); i++) {
                if (!st.empty() && s[i] == 'b' && st.top() == 'a') {
                    maxpoint += x;
                    st.pop();

                } else {
                    st.push(s[i]);
                }
            }
            string rem;
            while (!st.empty()) {
                rem += st.top();
                st.pop();
            }
            reverse(rem.begin(), rem.end());
            for (int i = 0; i < rem.size(); i++) {
                if (!st.empty() && rem[i] == 'a' && st.top() == 'b') {
                    st.pop();
                    maxpoint += y;
                } else {
                    st.push(rem[i]);
                }
            }
        } else {
            for (int i = 0; i < s.size(); i++) {
                if (!st.empty() && s[i] == 'a' && st.top() == 'b') {
                    st.pop();
                    maxpoint += y;
                } else {
                    st.push(s[i]);
                }
            }
            string rem;
            while (!st.empty()) {
                rem += st.top();
                st.pop();
            }
            reverse(rem.begin(), rem.end());

            for (int i = 0; i < rem.size(); i++) {
                if (!st.empty() && rem[i] == 'b' && st.top() == 'a') {
                    st.pop();
                    maxpoint += x;
                } else {
                    st.push(rem[i]);
                }
            }
        }

        // for(int i=0;i<rem.size();i++){
        //    if(!st.empty()&&s[i]=='a'&&st.top()=='b')
        //    {
        //      st.pop();
        //      maxpoint+=x;
        //    } else if(!st.empty()&&s[i]=='b'&&st.top()=='a')
        //    {
        //      st.pop();
        //      maxpoint+=y;
        //    }
        //   else if(s[i]=='a'||s[i]=='b'){
        //      st.push(s[i]);
        //    }

        // }
        // int ans=max(maxpoint,max(xpoint,ypoint)) ;
        // return ans;
        return maxpoint;
    }
};