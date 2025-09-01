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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode* head, *tail;
        ListNode* p1=list1, *p2=list2;
        if(list1->val<=list2->val){
            head=list1;
            tail=list1;
            p1=p1->next;
        }
        else{
            head=list2;
            tail=list2;
            p2=p2->next;
        }
        while(p1 && p2){
            if(p1->val>p2->val){
                tail->next=p2;
                p2=p2->next;
            }else{
                tail->next=p1;
                p1=p1->next;
            }
            tail=tail->next;
        }

        if(p1) tail->next=p1;
        if(p2) tail->next=p2;
        return head;
    }
};