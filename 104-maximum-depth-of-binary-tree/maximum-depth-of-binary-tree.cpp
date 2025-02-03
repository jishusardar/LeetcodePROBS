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
    void count(TreeNode* root,int n,int &m)
    {
        if(!root->left&&!root->right){
            m=max(n,m);
            n--;
            return;
        }
        if(root->left)
        count(root->left,n+1,m);
        if(root->right)
        count(root->right,n+1,m);
    } 
    int maxDepth(TreeNode* root) {
        if(!root)
        return 0;
        int m=0;
        count(root,1,m);
        return m;
    }
};