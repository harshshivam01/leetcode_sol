class Solution {
    int helper(string &tiles,vector<bool>&use,set<string>&st){
   
        for(int i=0;i<tiles.size();i++){
            if(use[i]!=1){
                use[i]=1;
                s.push_back(tiles[i]);
                st.insert(s);
                helper(tiles,use,st);
                use[i]=0;
                s.pop_back();
            }
            
           
        }
        return st.size();
    }
    string s;
public:
    int numTilePossibilities(string tiles) {
       sort(tiles.begin(),tiles.end());
       vector<bool>use(tiles.size(),0);
       set<string>st;
       return helper(tiles,use,st);
    }
};