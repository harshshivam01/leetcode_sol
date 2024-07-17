class Solution {
public:
    void f(TreeNode* root, vector<int>& to_delete, vector<TreeNode*>& ans) {
        if (root == NULL)
            return;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (find(to_delete.begin(), to_delete.end(), node->val) != to_delete.end()) {
                if (node->left) {
                    q.push(node->left);
                    if (find(to_delete.begin(), to_delete.end(), node->left->val) == to_delete.end()) {
                        ans.push_back(node->left);
                    }
                }
                if (node->right) {
                    q.push(node->right);
                    if (find(to_delete.begin(), to_delete.end(), node->right->val) == to_delete.end()) {
                        ans.push_back(node->right);
                    }
                }
            } else {
                if (node->left) {
                    if (find(to_delete.begin(), to_delete.end(), node->left->val) != to_delete.end()) {
                        q.push(node->left);
                        node->left = NULL;
                    } else {
                        q.push(node->left);
                    }
                }
                if (node->right) {
                    if (find(to_delete.begin(), to_delete.end(), node->right->val) != to_delete.end()) {
                        q.push(node->right);
                        node->right = NULL;
                    } else {
                        q.push(node->right);
                    }
                }
            }
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;

        if (root && find(to_delete.begin(), to_delete.end(), root->val) == to_delete.end()) {
            ans.push_back(root);
        }

        f(root, to_delete, ans);
        return ans;
    }
};
