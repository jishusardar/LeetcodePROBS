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
    int leveel(TreeNode* root,int x,int count)
    {
        if(!root)
        return 0;
        if(root->val==x)
        return count;
        return leveel(root->left,x,count+1)+leveel(root->right,x,count+1);
    }
    bool parentof(TreeNode* root,int x,int y)
    {
        if(!root)
        return 0;
        if(root->left&&root->right){
            if(root->left->val==x&&root->right->val==y)
            return 1;
            if(root->left->val==y&&root->right->val==x)
            return 1;
        }
        return parentof(root->left,x,y)||parentof(root->right,x,y);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int l1=-1;
        int l2=-1;
        if(x==y)
        return 0;
        l1=leveel(root,x,0);
        l2=leveel(root,y,0);
        if(l1==-1||l2==-1)
        return 0;
        if(l1!=l2)
        return 0;
        return !parentof(root,x,y);
    }
};