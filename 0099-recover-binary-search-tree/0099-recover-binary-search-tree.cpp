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
    void inorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL)
            return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    void recoverTree(TreeNode* root) {
        vector<int> sortedVals;
        inorder(root, sortedVals);
        sort(sortedVals.begin(), sortedVals.end());
        TreeNode* current = root;
        int index = 0;

        while (current != nullptr) {

            if (current->left == nullptr) {

                if (current->val != sortedVals[index]) {

                    current->val = sortedVals[index];
                }
                ++index;

                current = current->right;
            } else {

                TreeNode* predecessor = current->left;
                while (predecessor->right != nullptr &&
                       predecessor->right != current) {
                    predecessor = predecessor->right;
                }

                if (predecessor->right == nullptr) {

                    predecessor->right = current;

                    current = current->left;
                } else {

                    predecessor->right = nullptr;

                    if (current->val != sortedVals[index]) {

                        current->val = sortedVals[index];
                    }
                    ++index;

                    current = current->right;
                }
            }
        }
    }
};