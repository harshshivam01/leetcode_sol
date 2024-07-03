/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    // bool search(Node* root, int x) {
    //     // Your code here
    //     if (root == NULL)
    //         return 0;
    //     if (x == root->data)
    //         return 1;
    //     if (x > root->data)
    //         search(root->right, x);
    //     else
    //         search(root->left, x);
    // }
    set<int>st;
     bool findTarget(TreeNode* root, int k) { 
        
        if(root==NULL)return false;
        int target = k - root->val;
        if(st.find(target)!=st.end())return true;
        else st.insert(root->val);
       
        bool left=findTarget(root->left,k);
       bool right= findTarget(root->right,k);
        return left||right;
     }
};