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
    void inor(TreeNode* root,vector<int>&arr)
    {
        if(!root)
        return;
        inor(root->left,arr);
        arr.push_back(root->val);
        inor(root->right,arr);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int>arr;
        inor(root,arr);
        int ans=INT_MAX;
        for(int i=0;i<arr.size()-1;i++){
            ans=min(arr[i+1]-arr[i],ans);
        }
        return ans;
    }
};