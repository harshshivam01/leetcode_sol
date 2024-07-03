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
     int helper(TreeNode* root, unordered_map<TreeNode*,int>&mp){
        if(root==nullptr)return 0;
        int left=helper(root->left,mp);
        int right=helper(root->right,mp);
        mp[root]=left;
        return left+right+1;


     }
    int kthSmallest(TreeNode* root, int k) {
        unordered_map<TreeNode*,int>mp;
        helper(root,mp);
         while (root != nullptr) {
        int leftSize = mp[root] + 1;
        if (leftSize == k) return root->val;
        else if (leftSize > k) root = root->left;
        else {
            root = root->right;
            k -= leftSize;
        }
    }

    return -1;
    }
};