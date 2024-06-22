

class Solution {
public:
    std::vector<int> presmaller1(const std::vector<int>& arr) {
        int n = arr.size();
        std::stack<int> st;
        std::vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            ans[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    std::vector<int> nextsmaller1(const std::vector<int>& arr) {
        int n = arr.size();
        std::stack<int> st;
        std::vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            ans[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(std::vector<int>& heights) {
        int n = heights.size();
        std::vector<int> presmaller = presmaller1(heights);
        std::vector<int> nextsmaller = nextsmaller1(heights);
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            int width = nextsmaller[i] - presmaller[i] - 1;
            int curr = width * heights[i];
            maxi = std::max(maxi, curr);
        }
        return maxi;
    }
};

