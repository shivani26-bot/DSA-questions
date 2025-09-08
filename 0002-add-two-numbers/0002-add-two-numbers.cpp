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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1=l1;
        ListNode* curr2=l2;
        ListNode* temp;
        ListNode* sumHead;
        ListNode* curr;
        int value;
        int carry=0;
        int sum=curr1->val + curr2->val +carry;
         value= sum%10;
    carry= sum/10;
       temp= new ListNode(value);
       sumHead= temp;
       curr=sumHead;
    //    curr=temp;
    curr1=curr1->next;
    curr2=curr2->next;
        while(curr1 && curr2){
             sum= curr1->val + curr2->val + carry;
             value= sum%10;
             carry=sum/10;
             temp=new ListNode(value);
             curr->next=temp;
             curr=curr->next;
        //   curr=temp;
             curr1=curr1->next;
             curr2=curr2->next;
        }
        if(curr1){
            while(curr1){
                sum=curr1->val +carry;
                value=sum%10;
                carry=sum/10;
                temp=new ListNode(value);
                curr->next=temp;
                curr= curr->next;
                curr1=curr1->next;
            }
        }
        if(curr2){
while(curr2){
    sum=curr2->val +carry;
    value= sum%10;
    carry=sum/10;
    temp= new ListNode(value);
    curr->next= temp;
    curr =curr->next;
    curr2=curr2->next;
}
  }
if(carry!=0){
     temp= new ListNode(carry);
     curr->next=temp;
}

    return sumHead;  
    }
};