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
int getLinkedListLength(ListNode* temp){
    int len=0;
    while(temp){
        len++;
        temp=temp->next;
    }
    return len;
}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // we can use hashset 
        int lenA=getLinkedListLength(headA);
        int lenB=getLinkedListLength(headB);
        while(lenA>lenB){
            headA=headA->next;
            lenA--;
        }
        while(lenB>lenA){
            headB=headB->next;
            lenB--;
        }
        while(headA && headB){
            if(headA==headB){
                return headA;
            }
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
};