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
// int llLength(ListNode* head){
//     int count=0;
//     while(head){
//         count++;
//         head=head->next;
//     }
//     return count;
// }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // int length=llLength(head);
        // int pos=length-n;
        // ListNode* curr=head;
        // if(pos-1<0){
        //     return head->next;
        // }
        // while(pos-1>0){
        //     curr=curr->next;
        //     pos--;
        // }
        
        // ListNode* next=curr->next->next;
        // ListNode* prev=curr;
        // curr=curr->next;
        // prev->next=next;
        // delete(curr);
        // return head;

ListNode* p1=head;
ListNode* p2=head;
int count=0;
while(count<n){
    p1=p1->next;
    count++;
}
// p2 always points to the node before the deleted node position 
if(!p1){
    ListNode* temp=head->next;
    delete(head);
    return temp;
}
// if n-1th node is to be deleted from the end then p1->next will be null 
while(p1->next){
p1=p1->next;
p2=p2->next;
}
ListNode* curr=p2->next;
p2->next=curr->next;
delete(curr);
return head;
    }
};