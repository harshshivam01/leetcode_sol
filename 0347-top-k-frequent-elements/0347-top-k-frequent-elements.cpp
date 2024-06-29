class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int ,int>mp;
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        for(auto it :nums){
            mp[it]++;
        }
        for(auto it :mp){
            pq.push({it.second,it.first});
        }
        for(int i=0;i<k;i++){
           ans.push_back(pq.top().second);
           pq.pop();
        }
        return ans;
    }
};