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
class Solution {
public:
    ListNode* mergel(ListNode* head1,ListNode* head2)
    {
        ListNode* ans=new ListNode(0);
        ListNode* temp=ans;
        while(head1&&head2){
            if(head1->val>head2->val){
                temp->next=head2;
                head2=head2->next;
                temp=temp->next;
            }
            else{
                temp->next=head1;
                head1=head1->next;
                temp=temp->next;
            }
        }
        while(head1){
            temp->next=head1;
            head1=head1->next;
            temp=temp->next;
        }
        while(head2){
            temp->next=head2;
            head2=head2->next;
            temp=temp->next;
        }
        return ans->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
        return NULL;
        ListNode* ans=lists[0];
        for(int i=1;i<lists.size();i++){
            ans=mergel(ans,lists[i]);
        }
        return ans;
    }
};