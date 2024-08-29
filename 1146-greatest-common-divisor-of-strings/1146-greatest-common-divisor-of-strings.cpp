class Solution {
public:
    bool check(string ans, string str1) {
        int n = ans.size();
        int m = str1.size();
        if (m % n != 0)
            return false;
        for (int i = 0; i < m; i += n) {
             if (str1.substr(i, n) != ans)return  false ;
        }
        return true;
    }
    string gcdOfStrings(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
      
        if (n > m)
            return gcdOfStrings(str2,str1);
        int i = 0;
        string ans = "";
        while (i < n) {
            ans = str2.substr(0,n-i);
            if (check(ans, str1)&&check(ans,str2)) {
                return ans;
            } else {
                i++;
            }
        }
        return "";
    }
};