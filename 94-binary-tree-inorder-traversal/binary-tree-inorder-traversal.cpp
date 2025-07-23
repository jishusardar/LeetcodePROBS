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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)
        return {};
        vector<int>ans;
    stack<TreeNode*>st;
    stack<bool>freq;
    st.push(root);
    freq.push(0);
    while (!st.empty()) {
        TreeNode* temp=st.top();
        st.pop();
        bool count=freq.top();
        freq.pop();
        if (!count) {
            if (temp->right) {
                st.push(temp->right);
                freq.push(0);
            }
            st.push(temp);
            freq.push(1);
            if (temp->left) {
                st.push(temp->left);
                freq.push(0);
            }
        }
        else{
            ans.push_back(temp->val);
        }
    }
    return ans;
    }
};