/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==NULL)return {};
    map<int,map<int,multiset<int>>>mp;
    pair<TreeNode*,pair<int,int>>pq;
    queue<pair<TreeNode*,pair<int,int>>>q; 
    vector<vector<int>>ans;

    q.push({root,{0,0}});
    while(!q.empty()){
       TreeNode*x=q.front().first;
       int k=q.front().second.first;
       int y=q.front().second.second;
       mp[y][k].insert(x->val);
       q.pop(); 
       if(x->left!=NULL)q.push({x->left,{k+1,y-1}});
       if(x->right!=NULL)q.push({x->right,{k+1,y+1}});
    }
    for(auto it :mp){
        vector<int>temp;
         for(auto q : it.second) {
                temp.insert(temp.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(temp);
        

    }
    return ans ;
    }
};