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
        ListNode* head,*temp;
        if(list1->val <=list2->val){
            head=list1;
            temp=head->next;
            head->next=NULL;
            head->next= mergeTwoLists(temp,list2);
        }
        else{
              head=list2;
            temp=head->next;
            head->next=NULL;
            head->next= mergeTwoLists(list1,temp);
        }
        return head;
    }
};