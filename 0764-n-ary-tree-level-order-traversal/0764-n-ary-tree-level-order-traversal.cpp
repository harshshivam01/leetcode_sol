/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*>q;
        vector<vector<int>>ans;
        if(root==NULL)return {};

      q.push(root);
      
      while(!q.empty()){
         vector<int>temp;
       
         int s=q.size();
         for(int i=0;i<s;i++){
           Node* x=q.front();
        
        temp.push_back(x->val);
        q.pop();
            for(int j=0;j<x->children.size();j++){
                q.push(x->children[j]);
                
            }
         }
         ans.push_back(temp);
      }

return ans;
    }
};