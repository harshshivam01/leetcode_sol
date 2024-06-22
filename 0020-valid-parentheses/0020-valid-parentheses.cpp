class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (st.empty() && (s[i] == ')' || s[i] == ']' || s[i] == '}')) {
                return false;
            } else if (!st.empty() && s[i] == ')' || s[i] == ']' ||
                       s[i] == '}') {
                if ((s[i] == ')' && st.top() == '(') ||
                     (s[i] == ']' && st.top() == '[') ||
                    (s[i] == '}' && st.top() == '{')) {
                    st.pop();
                } else
                    return false;
            } else {
                st.push(s[i]);
            }
        }

        return st.empty();
        // for (int i = 0; i < s.size(); i++) {
        //     if (s[i] == ')' && st.size() > 0 && st.top() == '(') {
        //         st.pop();
        //     } else if (s[i] == ']' && st.size() > 0 && st.top() == '[') {
        //         st.pop();
        //     } else if (s[i] == '}' && st.size() > 0 && st.top() == '{') {
        //         st.pop();
        //     } else {
        //         st.push(s[i]);
        //     }
        // }
        // return st.empty();
    }
};