class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
       if (nums.size() % k != 0) return false;
    priority_queue<int>pq;
    unordered_map<int,int>mp;
    for(auto it :nums){
        mp[it]++;
    }
       for(auto it : mp){
           pq.push(it.first);

       }
       while(!pq.empty()){
        int start=pq.top();
        for(int i=0;i<k;i++){
           int el=start-i;
         if(mp[el]==0)return false ;
         mp[el]--;
         if(mp[el]==0){
            if(!pq.empty() && pq.top()==el )pq.pop();
         }
           
           
        }
      }
       return true;

    }
};