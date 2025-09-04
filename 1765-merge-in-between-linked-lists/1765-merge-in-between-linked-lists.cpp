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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp=list1;
        for(int i=1;i<a;i++){
            temp=temp->next;
        }
        ListNode* curr=temp->next;
ListNode* curr1=curr;
        for(int i=a;i<b;i++){
            curr1=curr1->next;
        }
        ListNode* temp1=list2;
        while(temp1->next){
temp1=temp1->next;
        }
        temp1->next=curr1->next;
        temp->next=list2;
        delete(curr);
        return list1;
    }
};