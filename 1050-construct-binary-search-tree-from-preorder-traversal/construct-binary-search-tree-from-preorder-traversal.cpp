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
    TreeNode* CreateBST(TreeNode* root,int data)
    {
        if(!root){
            root=new TreeNode(data);
            return root;
        }
        if(root->val>data)
        root->left=CreateBST(root->left,data);
        if(root->val<data)
        root->right=CreateBST(root->right,data);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=NULL;
        for(int i=0;i<preorder.size();i++)
        root=CreateBST(root,preorder[i]);
        return root;
    }
};