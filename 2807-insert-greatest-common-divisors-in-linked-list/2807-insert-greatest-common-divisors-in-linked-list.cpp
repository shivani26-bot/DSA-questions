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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head->next) return head;
        ListNode* curr=head;
        ListNode* nxt=head->next;
while(nxt){
    int val1=curr->val;
    int val2=nxt->val;
    int gcdVal= __gcd(val1,val2);
    ListNode* newNode= new ListNode(gcdVal);
    curr->next=newNode;
    newNode->next=nxt;
    curr=nxt;
    nxt=nxt->next;

}
return head;
    }
};