class Solution {
private:
    TreeNode* buildTree( vector<int>& preorder, int &i, int low, int high) {
        int n = preorder.size();
        if (i == n||preorder[i] < low||preorder[i] > high)
            return NULL;
            int val=preorder[i++];
            TreeNode*root=new TreeNode(val);
            root->left=buildTree(preorder,i,low,val);
            root->right=buildTree(preorder,i,val,high);
            return root;
        // if (preorder[i] < high && preorder[i] > low) {
        //     if (preorder[i] <= root->val) {
        //         if (root->left == NULL) {
        //             root->left = new TreeNode(preorder[i]);
        //             i = buildTree(root->left, preorder, i + 1, low, root->val);
        //         } else {
        //             i = buildTree(root->left, preorder, i, low, root->val);
        //         }
        //     } else {
        //         if (root->right == NULL) {
        //             root->right = new TreeNode(preorder[i]);
        //             i = buildTree(root->right, preorder, i + 1, root->val, high);
        //         } else {
        //             i = buildTree(root->right, preorder, i, root->val, high);
        //         }
        //     }
        // }
        // return i;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
       
       
        int i=0;
        return buildTree( preorder, i, INT_MIN, INT_MAX);
    }
};