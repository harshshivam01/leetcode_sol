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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode*temp=new TreeNode(val);
       
        if(root==NULL)return temp;
        if(val>root->val)insertIntoBST(root->right,val);
        else insertIntoBST(root->left,val);
        if(val<root->val&&root->left==NULL)
          root->left=temp;
        if(val>root->val&&root->right==NULL)  root->right=temp;
        return root;
    }
};