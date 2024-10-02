class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp;
        temp = arr;
        sort(temp.begin(), temp.end());
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++) {
            if (mp.find(temp[i]) == mp.end()){
                mp[temp[i]] = mp.size()+1;
            }
              
        }
        vector<int> ans;
        for (int i = 0; i < arr.size(); i++) {
            ans.push_back(mp[arr[i]]);
        }
        return ans;
    }
};