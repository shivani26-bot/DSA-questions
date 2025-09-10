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
ListNode* reverseList(ListNode* head){
    if(!head || !head->next) return head;
    ListNode* temp=head->next;
    head->next=NULL;
    ListNode* head1= reverseList(temp);
    temp->next=head;
    return head1;
}
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        

        int count=1;
        ListNode* prev=NULL,*curr=head;
        //reach left position, curr points to the left node and prev points just before curr node
        while(count!=left){
            prev=curr;
            curr=curr->next;
            count++;
        }
        ListNode* start=curr; //tell the start of ll from where we have to reverse
        //reach left position, no need of prev here
        while(count!=right){
            curr=curr->next;
            count++;
        }
   ListNode* rest=curr->next;//points to the rest of ll after right position
curr->next=NULL;//1->2->3->4->null 5, curr is 4, l=2 r=4, prevnode=1,startnode=2

ListNode* newHead=reverseList(start);//reverse the list to find the new head for ll from posiiton l to r
if(prev){
    prev->next=newHead;//if prev node is not null attach it to newhead, but if prev is null it means we reversed from l-1 position return newhead
}

//now attach the end of reversed list to rest of ll
curr=newHead;
while(curr->next){
    curr=curr->next;
}
curr->next=rest;
if(left==1) return newHead;
else return head;
    }
};