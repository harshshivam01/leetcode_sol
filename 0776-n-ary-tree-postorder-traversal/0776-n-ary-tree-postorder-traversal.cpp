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
    void helper(Node*root,vector<int>&ans){
        if(root==NULL)return ;
        int n =root->children.size();
        for(int i=0;i<n;i++){
            helper(root->children[i],ans);
        }
       
        ans.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        if(root==NULL)return {};
        vector<int >ans;
        helper(root,ans);
        
        return ans ;
    }
};