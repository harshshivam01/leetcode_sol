class Solution {
public:
    bool isvowel(char s) {
        if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u') {
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int i = 0;
        int j = 0;
        int count = 0;
        int maxcount = 0;
        while (j < k) {
        if (isvowel(s[j])) {
            count++;
        }
        j++;
    }
        maxcount = count;
        while (j < s.size()) {
            if (isvowel(s[j]))
                count++;

            if (isvowel(s[i]))
                count--;
            i++;
            j++;
            maxcount = max(maxcount, count);
        }
        return maxcount;
    }
};