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
    TreeNode* CreateBST(vector<int>&nums,int &index,int lower,int upper)
    {
        if(index==nums.size()||nums[index]<lower||nums[index]>upper)
        return NULL;
        TreeNode* root=new TreeNode(nums[index++]);
        root->left=CreateBST(nums,index,lower,root->val);
        root->right=CreateBST(nums,index,root->val,upper);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        return CreateBST(preorder,index,INT_MIN,INT_MAX);
    }
};