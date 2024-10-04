class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int i=0;
        int j=skill.size()-1;
        int sum=skill[0]+skill[skill.size()-1];
        long long chem=0;
        while(i<j){
           if(skill[i]+skill[j]==sum){
            chem+=(skill[i]*skill[j]);
           }
           else{
            return -1;
           } 
           i++;j--;
        }
        return chem;
    }
};