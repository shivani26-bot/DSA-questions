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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* prev=head;
        ListNode* curr=head->next;
        while(curr!=NULL){
        if(curr->val==prev->val){
  while( curr && curr->val==prev->val){
            curr=curr->next;
        }
        prev->next=curr;
        prev=curr;
        if(curr)
        curr=curr->next;
        }
        else{
            prev=prev->next;
            curr=curr->next;
        }
        }
        return head;
    
    }
};



// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {

//         if(!head || !head->next) return head;
//         ListNode* curr=head->next;
//         ListNode* prev=head;
//         while(curr){
//             if(curr->val != prev->val){
//                 prev->next=curr;
//                 prev=curr;
            
//             }
//             else{
//                 prev->next=curr->next;
//             }
//             curr=curr->next;
//         }
//         return head;
//     }
// };