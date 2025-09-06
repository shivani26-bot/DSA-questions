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
int llLength(ListNode* head){
    int count=0;
    while(head){
        count++;
        head=head->next;
    }
    return count;
}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length=llLength(head);
        int pos=length-n;
        ListNode* curr=head;
        if(pos-1<0){
            return head->next;
        }
        while(pos-1>0){
            curr=curr->next;
            pos--;
        }
        
        ListNode* next=curr->next->next;
        ListNode* prev=curr;
        curr=curr->next;
        prev->next=next;
        delete(curr);
        return head;


    }
};