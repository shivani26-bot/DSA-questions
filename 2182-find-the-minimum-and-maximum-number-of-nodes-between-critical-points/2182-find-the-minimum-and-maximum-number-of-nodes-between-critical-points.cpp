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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        // if only two nodes are there then return {-1,-1} because there will be no local maxima and local minima nodes
        if(!head->next->next) return {-1,-1};
        ListNode* temp=head->next;
        ListNode* prev=head;
        ListNode* next=temp->next;
        int pos=2;//because temp starts from 2nd node
vector<int>ans;
vector<int>position;
while(temp->next->next){
        if(temp->val>prev->val && temp->val>next->val){
            //store the position of critical point
            position.push_back(pos);
        }
else if(temp->val<prev->val && temp->val<next->val){
     //store the position of critical point
    position.push_back(pos);
}

    prev=temp;
    temp=next;
    next=temp->next;
        pos++;
}

//handle the last node
 if(temp->val>prev->val && temp->val>next->val){
            //store the position of critical point
            position.push_back(pos);
        }
if(temp->val<prev->val && temp->val<next->val){
     //store the position of critical point
    position.push_back(pos);
}

// [2,3,3,2]
if(position.size()<=1) return {-1,-1};
int maxDistance=position[position.size()-1]- position[0];
int minDistance=INT_MAX;


for(int i=1;i<position.size();i++){
    minDistance= min(minDistance, position[i]-position[i-1]);
}
ans.push_back(minDistance);
ans.push_back(maxDistance);


return ans;
    //     vector<int>ans;
    //     if(head->next->next==nullptr) return {-1,-1};
    //         vector<int>position;
    //     ListNode* temp= head->next;
    //     ListNode*prev= head;
    //     ListNode* nxt=temp->next;
    //     int pos=2;
    //     while(temp->next->next){
    //       if(temp->val<prev->val && temp->val<nxt->val){
    //         position.push_back(pos);
    //         // prev=temp;
    //         // temp=nxt;
    //         // nxt=temp->next;
    //         // pos++;
    //       }
    //       else if(temp->val>prev->val && temp->val>nxt->val){
    //         position.push_back(pos);
    //         // prev=temp;
    //         // temp=nxt;
    //         // nxt=temp->next;
    //         // pos++;
    //       }
    //        prev=temp;
    //         temp=nxt;
    //         nxt=temp->next;
    //         pos++;
    //     }

    //      if(temp->val<prev->val && temp->val<nxt->val){
    //         position.push_back(pos);
           
    //       }
    //      if(temp->val>prev->val && temp->val>nxt->val){
    //         position.push_back(pos);
           
    //       }
    //     for(int i=0;i<position.size();i++){
    //         cout<<position[i]<<" ";
    //     }
    //     if(position.size()<=1) return {-1,-1};
    //     int n= position.size();
    //     int maxDistance= position[n-1]-position[0];
    //     int minDistance=INT_MAX;
    //   for(int i=1;i<n;i++){
    //   minDistance=min(minDistance, position[i]-position[i-1]);
    //   }
    //     ans.push_back(minDistance);
    //     ans.push_back(maxDistance);
    //     return ans;
    //     // return position;
    }
};

// 2213
// 2332