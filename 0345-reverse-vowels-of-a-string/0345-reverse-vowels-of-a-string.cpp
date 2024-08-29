class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
       
        string st = "";
        while (i < s.size()) {

            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
                s[i] == 'O' || s[i] == 'U') {
                st += s[i];
            }
            i++;
        }
        i = 0;
       int j = st.size() - 1;
        while( i < s.size()) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
                s[i] == 'O' || s[i] == 'U') {
                s[i] = st[j];
                j--;
            }
            i++;
        }
        return s;
    }
};