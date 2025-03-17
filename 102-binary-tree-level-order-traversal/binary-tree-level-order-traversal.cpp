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
   void level(vector<vector<int>>&ans,queue<TreeNode*>&q)
   {
       while(!q.empty()){
       int n=q.size();
       vector<int>arr;
         while(n--){
         TreeNode* temp=q.front();
         q.pop();
         if(temp->left){
            arr.push_back(temp->left->val);
            q.push(temp->left);
         }
         if(temp->right){
            arr.push_back(temp->right->val);
            q.push(temp->right);
         }
       }
       if(arr.size())
       ans.push_back(arr);
       }
   }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
        return ans;
        queue<TreeNode*>q;
        q.push(root);
        ans.push_back({q.front()->val});
        level(ans,q);
        return ans;
    }
};