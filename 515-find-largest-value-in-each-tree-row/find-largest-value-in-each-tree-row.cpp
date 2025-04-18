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
    void largest(TreeNode* root,vector<int>&ans)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int maxi=INT_MIN;
            int n=q.size();
            while(n--){
                TreeNode* temp=q.front();
                q.pop();
                maxi=max(maxi,temp->val);
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
            }
            ans.push_back(maxi);
        }
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        if(!root)
        return ans;
        largest(root,ans);
        return ans;
    }
};