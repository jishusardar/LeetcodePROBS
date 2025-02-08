/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)
        return NULL;
        Node* temp=head;
        vector<Node*>childs;
        while(temp->next||temp->child){
            if(temp->child){
                if(temp->next)
                childs.push_back(temp->next);
                temp->next=temp->child;
                temp->child->prev=temp;
                temp=temp->child;
            }
            else
            temp=temp->next;
        }
        while(childs.size()!=0){
            Node* curr=childs[childs.size()-1];
            temp->next=curr;
            curr->prev=temp;
            temp=temp->next;
            while(temp->next)
            temp=temp->next;
            childs.pop_back();
        }
        for(Node* i=head;i!=NULL;i=i->next){
            i->child=NULL;
        }
        return head;
    }
};