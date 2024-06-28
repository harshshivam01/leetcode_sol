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
    int diameterOfBinaryTree(TreeNode* root) {
        
      diameter(root);
      return maxd;
    }
private:
 int maxd=0;
  int diameter(TreeNode*root){
   
     if(root==NULL){return 0 ;}
        int left= diameter(root->left);
        int right=diameter(root->right);
        maxd=max(maxd,left+right);
        return max(left,right)+1;
  }
     


};