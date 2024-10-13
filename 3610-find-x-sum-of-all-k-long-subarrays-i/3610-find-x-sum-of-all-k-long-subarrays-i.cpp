class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
           int n = nums.size();
        std::vector<int> answer(n - k + 1);
        
        for (int i = 0; i <= n - k; ++i) {
            answer[i] = calculateXSum(std::vector<int>(nums.begin() + i, nums.begin() + i + k), x);
        }
        
        return answer;
    }
    
private:
    int calculateXSum(std::vector<int> subarray, int x) {
        std::unordered_map<int, int> freq;
        for (int num : subarray) {
            freq[num]++;
        }
        
        std::vector<std::pair<int, int>> freqPairs(freq.begin(), freq.end());
        std::sort(freqPairs.begin(), freqPairs.end(), 
                  [](const auto& a, const auto& b) {
                      return a.second > b.second || (a.second == b.second && a.first > b.first);
                  });
        
        int sum = 0;
        for (int i = 0; i < std::min(x, static_cast<int>(freqPairs.size())); ++i) {
            sum += freqPairs[i].first * freqPairs[i].second;
        }
        
        return sum;
    }
    
};