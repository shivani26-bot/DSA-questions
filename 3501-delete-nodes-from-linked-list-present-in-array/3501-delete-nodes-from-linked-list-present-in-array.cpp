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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int>st(nums.begin(),nums.end());
        while(st.find(head->val)!=st.end()){
            head=head->next;
        }
        // if we don't enter the above while loop ,it means the current head val is not included in the nums as number to be deleted
        ListNode* temp=head->next;
        ListNode* prev=head;
        while(temp){
            //always check the current temp value is present in the set or not, or it's the candidate to be deleted
            if(st.find(temp->val)!=st.end()){
temp=temp->next;
prev->next=temp; //remove the link and join it to next element
            }else{
                // if not present in set, move the prev and temp pointers 
prev=temp;
temp=temp->next;
            }
        }
        return head;
    }
};