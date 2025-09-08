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
        ListNode* h1=l1,*h2= l2;
int carry=0;
ListNode* newHead=NULL;
ListNode* newNode, *temp;
        while(h1 && h2){
int totalSum=(h1->val+h2->val+carry);
int digit=(totalSum)%10;
carry=totalSum/10;
newNode= new ListNode(digit);
if(!newHead){
    newHead= newNode;
    temp=newHead;
}
else{
    temp->next=newNode;
    temp=newNode;
}

cout<<"total"<< " "<<totalSum<<endl;
cout<<"carry"<< " "<<carry<<endl;
h1=h1->next;
h2=h2->next;
        }
        while(h1){
            int totalSum=(h1->val+carry);
            int digit=(totalSum)%10;
carry=totalSum/10;
newNode= new ListNode(digit);
if(!newHead){
    newHead= newNode;
    temp=newHead;
}
else{
    temp->next=newNode;
    temp=newNode;
}
h1=h1->next;
        }
          while(h2){
            int totalSum=(h2->val+carry);
            int digit=(totalSum)%10;
carry=totalSum/10;
newNode= new ListNode(digit);
if(!newHead){
    newHead= newNode;
    temp=newHead;
}
else{
    temp->next=newNode;
    temp=newNode;
}

h2=h2->next;
        }
        if(carry){
            newNode= new ListNode(carry);
             temp->next=newNode;
    temp=newNode;
        }
return newHead;
    }
};