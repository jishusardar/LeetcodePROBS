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
    int find(vector<int>&in,int start,int end,int target)
    {
        for(int i=start;i<=end;i++){
            if(in[i]==target)
            return i;
        }
        return -1;
    }
    TreeNode* CreateTree(vector<int>&in,vector<int>&pre,int Instart,int Inend,int index)
    {
        if(Instart>Inend)
        return NULL;
        TreeNode* root=new TreeNode(pre[index]);
        int pos=find(in,Instart,Inend,pre[index]);
        root->left=CreateTree(in,pre,Instart,pos-1,index+1);
        root->right=CreateTree(in,pre,pos+1,Inend,index+(pos-Instart)+1);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return CreateTree(inorder,preorder,0,inorder.size()-1,0);
    }
};