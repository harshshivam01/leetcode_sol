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
    void helper(TreeNode* root, int isleft, int len, int& maxi) {
        if (root == NULL)
            return;
        maxi = max(maxi, len) ;
        if (isleft) {
            helper(root->left, 1, 1, maxi);
            helper(root->right, 0, len+1, maxi);
        }
        else {
            helper(root->left, 1, len+1, maxi);
            helper(root->right, 0, 1, maxi);
        }
    }
    int longestZigZag(TreeNode* root) {

        int maxi = 0;
        helper(root->left, 1, 1, maxi);
        helper(root->right, 0, 1, maxi);
        return maxi;
    }
};