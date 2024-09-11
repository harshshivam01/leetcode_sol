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
//    TreeNode* helper(TreeNode*root,int key){
//        if(root==NULL)return ;
//        if(root->val==key){
//         if(root->left)
//        }
//    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return NULL;
        if(root->val==key){
            if(root->left!=NULL&&root->right!=NULL){
                TreeNode*temp=root->right;
                while(temp->left!=NULL){
                    temp=temp->left;
                }
               root->val=temp->val;

               root->right=deleteNode(root->right,temp->val);
            }else{
                TreeNode*temp;
                if(root->left!=NULL)temp=root->left;
                else{
                    temp=root->right;
                }
                delete root;
                return temp;
            }
        }else if(root->val>key){
            root->left=  deleteNode(root->left,key);
        }else{
           root->right= deleteNode(root->right,key);
        }
   
        return root;
    }
};