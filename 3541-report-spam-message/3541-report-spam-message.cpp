class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
         std::unordered_set<std::string> bannedSet(bannedWords.begin(), bannedWords.end());
        
        int matchCount = 0;
        for (const auto& word : message) {
            if (bannedSet.count(word) > 0) {
                matchCount++;
            }
            if (matchCount >= 2) {
                return true;
            }
        }
        
        return false;
    }
};