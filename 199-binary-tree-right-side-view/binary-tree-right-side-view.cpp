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
  void traverse(TreeNode* root,int i,vector<int>&ans)
  {
    if(!root)
    return;
    if(i==ans.size())
    ans.push_back(root->val);
    if(root->right)
    traverse(root->right,i+1,ans);
    if(root->left)
    traverse(root->left,i+1,ans);
  }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        traverse(root,0,ans);
        return ans;
    }
};