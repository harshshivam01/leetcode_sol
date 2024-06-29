class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
    //    priority_queue<int ,vector<int>,greater<int>>pq;
     if (hand.size() % groupSize != 0) return false;
    priority_queue<int>pq;
    unordered_map<int,int>mp;
    for(auto it :hand){
        mp[it]++;
    }
       for(auto it : mp){
           pq.push(it.first);

       }
       while(!pq.empty()){
        int start=pq.top();
        for(int i=0;i<groupSize;i++){
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