class Solution {
    int total = 0;

public:
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr) return 0;
        helper(root, sum, 0);
        pathSum(root->left, sum);
        pathSum(root->right, sum);
        return total;
    }

private:
    void helper(TreeNode* root, int sum, long long curr) {
        if (root == nullptr) return;
        curr += root->val;
        if (curr == sum) total++;
        helper(root->left, sum, curr);
        helper(root->right, sum, curr);
    }
};
