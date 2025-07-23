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
    int position(vector<int>&in,int start,int end,int val){
        for(int i=start;i<=end;i++){
            if(in[i]==val)
            return i;
        }
        return -1;
    }
    TreeNode* ConstructTree(vector<int>&in,vector<int>&post,int start,int end,int index){
        if(start>end)
        return NULL;
        TreeNode* root=new TreeNode(post[index]);
        int pos=position(in,start,end,post[index]);
        root->right=ConstructTree(in,post,pos+1,end,index-1);
        root->left=ConstructTree(in,post,start,pos-1,index-(end-pos)-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return ConstructTree(inorder,postorder,0,inorder.size()-1,inorder.size()-1);
    }
};