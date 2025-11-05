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
// time: each node is visited once for each node o(1) operation is done, hence total tc: o(n)
// space: o(1) no recursion here
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nextNode=head->next;
        while(nextNode){
            nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
            
        }
        return prev;
    }
};