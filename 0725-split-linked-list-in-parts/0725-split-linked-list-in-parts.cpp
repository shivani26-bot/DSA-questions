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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp=head;
        int llLength=0;
        while(temp){
          llLength++;
         temp=temp->next;
        }
        vector<ListNode*>result;
        if(llLength<=k){
            while(head){
            ListNode* curr=head;
            result.push_back(curr);
             head=head->next;
            curr->next=NULL;
           
            curr=head;
           
            k--;
        }
            while(k!=0){
                result.push_back(NULL);
                k--;
            }
        }
        else{
            while(k!=1){
            int partLen= ceil((float) llLength/(float) k);
            llLength-=partLen;
k--;
             ListNode* curr=head;
           while(partLen!=1){
          
         
           curr=curr->next;
 partLen--;
            }
              result.push_back(head);
 head=curr->next;

 curr->next=NULL;


            }          
             result.push_back(head);   
            }
        return result;
    }
};