class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (auto it : asteroids) {
            bool exploded = false;

            while (!st.empty() && it < 0 && st.top() > 0) {
                if (st.top() < -it) {
                    st.pop();  // The top of the stack is destroyed
                    continue;  // Continue to check the next top of the stack
                } else if (st.top() == -it) {
                    st.pop();  // Both asteroids are destroyed
                    exploded = true;
                    break;
                } else {
                    exploded = true;  // The current asteroid is destroyed
                    break;
                }
            }

            if (!exploded) {
                st.push(it);  // If it is not destroyed, push it onto the stack
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());  // The stack is in reverse order, so we need to reverse it back
        return ans;
    }
};
