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

// to find the middle node of linked list use slow and fast pointer concept 
// move slow by 1 step and fast by 2 step 
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head, *fast=head;
        while(fast && fast->next){
slow=slow->next;
fast=fast->next->next;
        }
        return slow;

    }
};