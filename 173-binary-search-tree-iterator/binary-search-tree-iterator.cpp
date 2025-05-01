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
 queue<int>q;
 void inorder(TreeNode* root,queue<int>&q)
 {
    if(!root)
    return;
    inorder(root->left,q);
    q.push(root->val);
    inorder(root->right,q);
 }
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        inorder(root,q);
    }
    
    int next() {
        int ans=q.front();
        q.pop();
        return ans;
    }
    
    bool hasNext() {
        if(!q.empty())
        return 1;
        return 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */