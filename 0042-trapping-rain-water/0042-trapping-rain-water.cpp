class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0 || n == 1) return 0;

        vector<int> left(n, 0);
        vector<int> right(n, 0);

        // Compute left maximums
        left[0] = height[0];
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], height[i]);
        }

        // Compute right maximums
        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], height[i]);
        }

        // Calculate the trapped water
        int water = 0;
        for (int i = 1; i < n - 1; i++) {
            water += max(0, min(left[i], right[i]) - height[i]);
        }

        return water;
       
    }
};