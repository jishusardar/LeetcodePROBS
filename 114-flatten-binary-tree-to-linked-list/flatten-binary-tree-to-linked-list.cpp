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
    void flatten(TreeNode* root) {
        while(root){
        if(root->left){
            TreeNode* curr=root->left;
            while(curr->right&&curr->right!=root)
            curr=curr->right;
            if(!curr->right){
                if(root->right)
                curr->right=root->right;
                root->right=root->left;
                root->left=NULL;
            }
        }
        else
        root=root->right;
    }

    }
};