class Solution {
public:
   
    bool canFinish(int mountainHeight, const vector<int>& workerTimes, long long time) {
       long long totalHeight = 0;
        for (int workerTime : workerTimes) {
            long long x = (sqrt(1.0 + 8.0 * time / workerTime) - 1) / 2;
            totalHeight += x;
            if (totalHeight >= mountainHeight) return true;
        }
        return false;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
         long long left = 1, right = 1e18;  // A large upper bound
        
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (canFinish(mountainHeight, workerTimes, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};