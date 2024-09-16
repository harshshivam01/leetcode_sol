
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> mini;
        for (int i = 0; i < timePoints.size(); i++) {
            int x;
            if (timePoints[i].substr(0, 2) == "00") {
                x = stoi(timePoints[i].substr(3, 2));
            } else {
                x = stoi(timePoints[i].substr(0, 2)) * 60 +
                    stoi(timePoints[i].substr(3, 2));
            }

            mini.push_back(x);
        }
        sort(mini.begin(), mini.end());
        int ans =INT_MAX;
        for(int i=0;i<mini.size()-1;i++){
            ans=min(ans,mini[i+1]-mini[i]);
        }
        int diff=(1440-mini.back()+mini.front());
          int y=min(ans,diff);
        return y;
    }
};