class Solution {
public:
    bool dfs(int i, vector<int>& visi, vector<int> &pathvisi,
             vector<int> adjList[]) {
        pathvisi[i] = 1;
        visi[i] = 1;
        for ( const auto& it : adjList[i]) {
            if (visi[it] == 0) {
                if (dfs(it,visi,pathvisi,adjList))return true;
            }
            else if(pathvisi[it]==1)return true;
        }
        pathvisi[i]=0;
        return false ;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // int n = prerequisites.size();
        // int m = prerequisites[0].size();

        vector<int> adjList[numCourses];

         for (const auto& pre : prerequisites) {
            adjList[pre[1]].push_back(pre[0]);
        }

        vector<int> visi( numCourses, 0);
        vector<int> pathvisi( numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (visi[i] == 0)
               if(dfs(i, visi, pathvisi, adjList))return false;
               
        }
      return true;

    }
};