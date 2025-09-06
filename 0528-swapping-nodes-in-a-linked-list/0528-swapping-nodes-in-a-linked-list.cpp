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
    ListNode* swapNodes(ListNode* head, int k) {
ListNode* slow=head,*fast=head;
int count=1;
while(count<k){
    fast=fast->next;
    count++;
}

ListNode* temp=fast;
while(fast->next){
    slow=slow->next;
    fast=fast->next;
}

swap(temp->val,slow->val);
return head;
    }
};