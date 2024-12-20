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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level=0;

        while(!q.empty()){
            int size=q.size();
            vector<TreeNode*>level_order;
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();
                level_order.push_back(curr);
                if(curr->left)
                q.push(curr->left);
                if(curr->right)
                q.push(curr->right);
            }
            if(level&1){
                int start=0,end=level_order.size()-1;
                while(start<end){
                    swap(level_order[start]->val,level_order[end]->val);
                    start++,end--;
                }
            }
            level++;
        }
        return root;
    }
};