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
    ListNode* partition(ListNode* head, int x) {
    //   we have to preserve the order
    //   all the smaller nodes than x should come on before x
    // 1->2->2->3->4->5 but this doesn't preserve the order 
    // its not mentioned that on right side of x elements should be greater than x
    // first write the element smaller than x then write the remaining as it is in their relative order 
    // 1->2->2->4->3->5
               
    // make two list smaller 1->2->2
    // large or equal 4->3->5 and join both the list
    ListNode* small=new ListNode(0);//kinda dummy node
    ListNode* large=new ListNode(0);

    ListNode* smallP=small;
    ListNode* largeP=large;

    while(head){
        if(head->val<x){
            smallP->next=head;
            smallP=smallP->next;
        }
        else{
            largeP->next=head;
            largeP=largeP->next;
        }
        head=head->next;
    }
smallP->next=large->next; //small p points to the last node of the smaller ll, hence attach it to the head of larger ll
largeP->next=NULL;
return small->next;

    
    }
};