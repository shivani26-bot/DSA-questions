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
ListNode* middleNode(ListNode* head){
    ListNode* slow=head,*fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
// ListNode* reverseList(ListNode* head){
// ListNode* prev=NULL;
// ListNode* curr=head, *nextNode=head;
// while(nextNode){
//     nextNode=curr->next;
//     curr->next=prev;
//     prev=curr;
//     curr=nextNode;
// }
// return prev;
// }
// recursive 
ListNode* reverseList(ListNode* head){
if(!head || !head->next) return head;
ListNode* temp=head->next;
head->next=NULL;
ListNode* head1=reverseList(temp);
temp->next=head;
return head1;
}
    bool isPalindrome(ListNode* head) {
     ListNode* mid=middleNode(head);  
     ListNode* head1=head;
     ListNode* head2=reverseList(mid); 
     while(head1 && head2){
        if(head1->val!=head2->val) return false;
        else{
          head1=head1->next;
          head2=head2->next;  
        }
     }
     return true;
    }
};