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
// 1->2->3->4->5->6 k=2
// length=6
// newhead will be 5, and new tail will be 4
// 5->6->1->2->3->4->null
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0) return head;
// count total nodes in the ll and find the tail so that we can form a cycle by joining the tail to head
        int lengthLL=1;
        ListNode* tail=head;
        while(tail->next){
            lengthLL++;
            tail=tail->next;
        }

// k>n then k must always be k=k%n
        k=k%lengthLL;
        if(k==0) return head;

// now join the tail to head to form the cycle
tail->next=head;

        
        // find how many steps to reach the new tail
        int stepsToNewHead= lengthLL-k;
        ListNode* newTail=tail;
        while(stepsToNewHead--){
            newTail=newTail->next;
        }
        
        //find newhead
ListNode* newHead=newTail->next;
//detach the newtail and point it to null
newTail->next=NULL;
return newHead;
   
    }
};