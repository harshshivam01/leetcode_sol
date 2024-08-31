class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
       std::string x = std::to_string(num1);
    std::string y = std::to_string(num2);
    std::string z = std::to_string(num3);

    x.insert(0, 4 - x.length(), '0');
    y.insert(0, 4 - y.length(), '0');
    z.insert(0, 4 - z.length(), '0');

    // Generate the key by taking the minimum digit at each position
    std::string ans;
    for (int i = 0; i < 4; i++) {
        char min_digit = std::min({x[i], y[i], z[i]});
        ans += min_digit;
    }

    // Convert the result to an integer to remove leading zeros
    return std::stoi(ans);
}
};