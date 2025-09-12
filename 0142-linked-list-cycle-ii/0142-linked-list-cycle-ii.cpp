/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        // first find whether ll has cycle or not , because it's not necessary that the point where slow and fast pointer will meet is the first node of the cycle, it can be anywhere in the cycle
        
        ListNode* slow=head,*fast=head;
        bool hasCycle=false;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) {
                hasCycle=true;
                break;
            }
        }
        if(!hasCycle) return NULL; //return null if there is no cycle
        ListNode* p=head;
        ListNode* temp=slow; 
        //to find the start point of the cycle again move the pointers by 1 step
        while(p!=temp){
            p=p->next;
            temp=temp->next;
        }
        return p;
    }
};