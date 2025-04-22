/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* ConstructBST(vector<int>&arr,int start,int end)
    {
        if(start>end)
        return NULL;
        int mid=start+(end-start)/2;
        TreeNode* temp=new TreeNode(arr[mid]);
        temp->left=ConstructBST(arr,start,mid-1);
        temp->right=ConstructBST(arr,mid+1,end);
        return temp;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>arr;
        while(head){
            arr.emplace_back(head->val);
            head=head->next;
        }
        return ConstructBST(arr,0,arr.size()-1);
    }
};