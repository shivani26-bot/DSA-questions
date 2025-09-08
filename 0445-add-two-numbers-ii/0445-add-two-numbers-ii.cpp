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
ListNode* reverseLL(ListNode* head){
if(!head || !head->next) return head;
    ListNode* temp=head->next;
    head->next=NULL;
    ListNode* head1= reverseLL(temp);
    temp->next=head;
    return head1;
}
    ListNode* addTwoNumber(ListNode* l1, ListNode* l2) {
        ListNode* h1=l1,*h2= l2;
int carry=0;
ListNode* newHead=NULL;
ListNode* newNode, *temp;
int totalSum,digit;
        while(h1 && h2){ totalSum=(h1->val+h2->val+carry); digit=(totalSum)%10;
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

// cout<<"total"<< " "<<totalSum<<endl;
// cout<<"carry"<< " "<<carry<<endl;
h1=h1->next;
h2=h2->next;
        }
        while(h1){
         totalSum=(h1->val+carry);
         digit=(totalSum)%10;
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
         totalSum=(h2->val+carry);
         digit=(totalSum)%10;
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h1=reverseLL(l1);
        ListNode* h2=reverseLL(l2);
ListNode* head=addTwoNumber(h1,h2);
return reverseLL(head);
    }
};