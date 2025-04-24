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
class Box
{
    public:
    bool BST;
    int sum;
    int min;
    int max;
    Box()
    {
        BST=1;
        sum=0;
        min=INT_MAX;
        max=INT_MIN;
    }
};
class Solution {
public:
    Box* find(TreeNode* root,int &ans)
    {
        if(!root){
            return new Box;
        }
        Box* lefth=find(root->left,ans);
        Box* righth=find(root->right,ans);
        if(lefth->BST&&righth->BST&&lefth->max<root->val&&righth->min>root->val)
        {
            Box* head=new Box;
            head->sum+=lefth->sum+righth->sum+root->val;
            head->min=min(lefth->min,root->val);
            head->max=max(righth->max,root->val);
            ans=max(ans,head->sum);
            return head;
        }
        else{
            lefth->BST=0;
            return lefth;
        }
    }
    int maxSumBST(TreeNode* root) {
        int ans=0;
        find(root,ans);
        return ans;
    }
};