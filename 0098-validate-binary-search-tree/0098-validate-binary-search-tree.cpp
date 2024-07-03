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
    bool f(TreeNode*root,long long low,long long  high){
        if(root==NULL)return true ;
        if(root->val<=low ||root->val>=high)return false;
        return f(root->left,low,root->val)&&f(root->right,root->val,high);
    }
    bool isValidBST(TreeNode* root) {
      return   f(root,-1e11,1e11);
    }
};