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
    void helper(TreeNode* root, int& count, int maxi) {
        if (root == NULL)
            return;

        if (root->val >= maxi) {
            maxi = root->val;
            count++;
        }
        if (root->left != NULL)
            helper(root->left, count, maxi);
        if (root->right != NULL)
            helper(root->right, count, maxi);
    }
    int goodNodes(TreeNode* root) {

        int count = 0;

        helper(root, count, root->val);
        return count;
    }
};