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
    class Box
    {
        public:
        bool BST;
        int sum;
        int min;
        int max;
        Box(int data)
        {
            BST=1;
            sum=data;
            min=data;
            max=data;
        }
    };
    Box* find(TreeNode* root,int &sum)
    {
        if(!root->left&&!root->right){
            Box* head=new Box(root->val);
            sum=max(sum,head->sum);
            return head;
        }
        else if(root->left&&!root->right){
            Box* temp=find(root->left,sum);
            if(temp->BST&&root->val>temp->max){
                Box* head=new Box(root->val);
                head->sum+=temp->sum;
                sum=max(sum,head->sum);
                head->min=temp->min;
                return head;
            }
            else{
                temp->BST=0;
                return temp;
            }
        }
        else if(root->right&&!root->left){
            Box* temp=find(root->right,sum);
            if(temp->BST&&temp->min>root->val){
                Box* head=new Box(root->val);
                head->sum+=temp->sum;
                sum=max(sum,head->sum);
                head->max=temp->max;
                return head;
            }
            else{
                temp->BST=0;
                return temp;
            }
        }
        else{
            Box* lefthead=find(root->left,sum);
            Box* righthead=find(root->right,sum);
            if(lefthead->BST&&righthead->BST&&lefthead->max<root->val&&righthead->min>root->val){
                Box* head=new Box(root->val);
                head->sum+=lefthead->sum+righthead->sum;
                sum=max(sum,head->sum);
                head->min=lefthead->min;
                head->max=righthead->max;
                return head;
            }
            else{
                lefthead->BST=0;
                return lefthead;
            }
        }
    }
    int maxSumBST(TreeNode* root) {
        int sum=0;
        find(root,sum);
        return sum;
    }
};