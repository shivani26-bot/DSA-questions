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
      //find the length of the linkedlist
      int llLength=0;
      ListNode* temp=head;
      while(temp){
        llLength++;
        temp=temp->next;
      }
      vector<ListNode*>result;
    //   there can be two cases
    // first lllength is <=k ex: lllength=3 k=3 then 3 partition , 1->null | 2->null |3->null
    // lllength=3 k=5 then 1->null| 2->null |3->null | null |null
    if(llLength<=k){
        while(head){
            ListNode* curr=head;
            result.push_back(curr);
            head=head->next;
            curr->next=NULL;
            curr=head;
            k--;
                    }
// if partition is still remaining to done k>llLength , then remaining partition will contain null
       while(k!=0){
        result.push_back(NULL);
        k--;
       }
    }
    // second lllength > k then each partition should have ceil value of llLength/k

    else{
        while(k!=1){
// find length of current partition , number of elements in current partition
int partLen=ceil((float)llLength/(float)k);
llLength-=partLen;
k--;
ListNode* curr=head;
while(partLen!=1){
    curr=curr->next;
    partLen--;
}
result.push_back(head);//push the head as it points to starting head of the partition
head=curr->next;//move the head to next partition
curr->next=NULL;

        }
        // for the last partition push as it is
        result.push_back(head);
    }
    return result;
    }
};