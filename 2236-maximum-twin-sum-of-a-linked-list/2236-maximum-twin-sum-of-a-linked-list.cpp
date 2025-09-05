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
ListNode* midElement(ListNode* head){
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

ListNode* reverseList(ListNode* head){
if(!head || !head->next) return head;
ListNode* temp=head->next;
    head->next=NULL;
    ListNode* head1= reverseList(temp);
    temp->next=head;
    return head1;

}
    int pairSum(ListNode* head) {
        ListNode* midNode=midElement(head);
       
        ListNode* head1= reverseList(midNode);
        cout<<head1->val;
int maxsum=INT_MIN;
        while(head && head1){
maxsum=max(maxsum,head->val+head1->val);
head=head->next;
head1=head1->next;
        }
return maxsum;
    
    }
};