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
    void inor(TreeNode* root,int &curr,int &prev,int &ans)
    {
        if(!root)
        return;
        inor(root->left,curr,prev,ans);
        curr=root->val;
        if(prev!=INT_MIN)
        ans=min(ans,curr-prev);
        prev=curr;
        inor(root->right,curr,prev,ans);
    }
    int minDiffInBST(TreeNode* root) {
        int ans=INT_MAX;
        int curr=root->val;
        int prev=INT_MIN;
        inor(root,curr,prev,ans);
        return ans;
    }
};