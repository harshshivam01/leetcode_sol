class Solution {
public:
    string stringHash(string s, int k) {
       string result;
    int n = s.length();

    
    for (int i = 0; i < n; i += k) {
        int sum = 0;

       
        for (int j = i; j < i + k; ++j) {
            sum += s[j] - 'a';
        }

        
        char hashedChar = 'a' + (sum % 26);
        result += hashedChar;
    }

    return result; 
    }
};