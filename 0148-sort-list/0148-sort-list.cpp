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
// use merge or quick sort 
// optimised sorting algos: merge sort and quick sort 
// merge sort: partition the array into middle , until there is only 1 element , once there is only 1 element we can merge it 
// 3->4->2->1->5->X
//  divide into middle
//     3->4->2->X           1->5->X  
//  3->4->X        2->X
// 3->X  4->X

// when reached single element try to merge them back while merging we merge them in sorted manner
// ms(arr,low,high){
//     if(low==high) return ;//single element
//     mid=(low+high)/2;
//     ms(arr,low,mid)
//     ms(arr,mid+1,high)
//     merge(arr,low,mid,high)//merge left and right
// }

// if length is even we want 2nd element to be middle, modify the algo 
// 1,2,3,4 then 2 should be middle 
ListNode* findMiddle(ListNode* head){
    //normally in tortoise and hare algo slow and fast always start from head
    ListNode* slow=head;
    ListNode* fast=head->next; //change in algo
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

//merge two sorted list 
ListNode* mergeTwoLists(ListNode* list1,ListNode* list2){
    ListNode* dummyNode=new ListNode(-1);
    ListNode* temp=dummyNode;
    while(list1 && list2){
        if(list1->val<list2->val){
            temp->next=list1;
            temp=list1;
            list1=list1->next;
        }
        else{
            temp->next=list2;
            temp=list2;
            list2=list2->next;
        }
    }
    if(list1) temp->next=list1;
    else temp->next=list2;
    return dummyNode->next;
}
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;//if head is null or only one element in linkedlist is there

        // first step is to find the middle 
        ListNode* middleNode= findMiddle(head); // to find the  middle we use tortoise and hare algo , time to find middle is o(n/2)
        ListNode* leftHead=head;
       ListNode* rightHead=middleNode->next;
        middleNode->next=NULL;
        //call the mergesort
        //returns sorted head which contains the left portion and right portion
leftHead=sortList(leftHead);
rightHead=sortList(rightHead);

        //combine the left and right, both the parts are sorted hence merge two sorted list
        // it returns the head of the sorted list 
        // 21. Merge Two Sorted Lists

        return mergeTwoLists(leftHead,rightHead); //o(n)
    }
};


// in array mergesort takes nlogn sc:o(n)
// in ll, time complexity: logn *(n+n/2)
// logn is recursion depth