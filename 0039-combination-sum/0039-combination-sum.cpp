class Solution {

    vector<vector<int>> ans;
 
    vector<int> temp;
   

 void helper(vector<int>& candidates, int target,int index) {
        if(target==0){
          ans.push_back(temp);
           return ;
        }
       
        for(int i=index;i<candidates.size();i++){
            if(candidates[i]>target)continue;
           temp.push_back(candidates[i]);
          
           helper(candidates, target-candidates[i],i);
           
           temp.pop_back();

        }

    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    
       
         helper(candidates, target,0);
       
         return ans ;
    }
};