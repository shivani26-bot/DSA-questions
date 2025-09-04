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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr=head;
ListNode* newHead=nullptr;
int sum;
while(curr){
        if(curr->val==0){
            curr=curr->next;
            sum=0;
        }
        else{
            while(curr->val!=0){
                sum+=curr->val;
                curr=curr->next;
            }
            ListNode* temp;
            if(!newHead){
                newHead=new ListNode(sum);
                temp=newHead;
            }
            else{
                temp->next=new ListNode(sum);
                temp=temp->next;
            }
        }
}
return newHead;
    }
};