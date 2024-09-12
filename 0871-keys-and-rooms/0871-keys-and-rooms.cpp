class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
       
        int n =rooms.size();
        vector<int>visi(n,0);
        visi[0]=1;
        queue<int>q;
        for(int i=0;i<rooms[0].size();i++){
            q.push(rooms[0][i]);
        }
      while(!q.empty()){
        int p=q.front();
        q.pop();
        if(visi[p]==0){
            visi[p]=1;
            for(int i=0;i<rooms[p].size();i++){
                q.push(rooms[p][i]);
            }
        }

      }
         for(int i=0;i<visi.size();i++){
            if(visi[i]==0)return false;
         }
         return true;
    }

};