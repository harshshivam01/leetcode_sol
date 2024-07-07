class Solution {
public:
    void backtrack(int n, string current, vector<string>& result) {
    if (current.length() == n) {
        result.push_back(current);
        return;
    }
    
    
    if (current.empty() || current.back() == '1') {
        backtrack(n, current + '0', result);
        backtrack(n, current + '1', result);
    } else if (current.back() == '0') {
        backtrack(n, current + '1', result);
    }
}
    vector<string> validStrings(int n) {
        vector<string>ans;
        string st="";
        backtrack(n,st,ans);
        return ans;
    }
};