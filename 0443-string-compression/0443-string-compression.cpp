class Solution {
public:
   
     int compress(vector<char>& chars) {
    if (chars.empty()) return 0;  // Handle empty input

    char temp = chars[0];
    vector<char> ans;  // Declare ans as a vector of characters
    int count = 1;

    for (int i = 1; i < chars.size(); i++) {
        if (temp == chars[i]) {
            count++;
        } else {
            // Add the previous character and its count (if > 1)
            ans.push_back(temp);
            if (count > 1) {
                string si = to_string(count);
                for (auto ch : si) {
                    ans.push_back(ch);
                }
            }
            // Reset count for new character
            temp = chars[i];
            count = 1;
        }
    }

    // Handle the last sequence
    ans.push_back(temp);
    if (count > 1) {
        string si = to_string(count);
        for (auto ch : si) {
            ans.push_back(ch);
        }
    }

    // Update original vector
    chars = ans;
    return ans.size();
}

}
;