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
    ListNode* insertionSortList(ListNode* head) {
//        First of all, we create an empty list which would be used to hold the results of sorting.
// We then iterate through each element in the input list. For each element, we need to find a proper position in the resulting list to insert the element, so that the order of the resulting list is maintained.
// As one can see, once the iteration in the above step terminates, we will obtain the resulting list where the elements are ordered.
// Algorithm
// To translate the above intuition into the implementation, we applied two tricks.
// The first trick is that we will create a dummy (pseudo_head) node which serves as a pointer pointing to the resulting list.
// More precisely, this node facilitates us to always get a hold on the resulting list, especially when we need to insert a new element to the head of the resulting list.
// One will see later in more details how it can greatly simplify the logic.
// In a singly-linked list, each node has only one pointer that points to the next node.
// If we would like to insert a new node (say B) before certain node (say A), we need to know the node (say C) that is currently before the node A, i.e. C -> A.
// With the reference in the node C, we could now insert the new node, i.e. C -> B -> A.
// Given the above insight, in order to insert a new element into a singly-linked list, we apply another trick.
// The idea is that we use a pair of pointers (namely prev -> next) which serve as place-holders to guard the position where in-between we would insert a new element (i.e. prev -> new_node -> next).

// create a dummy node 
ListNode* dummy=new ListNode(); //contain resuting list
ListNode* curr=head;//points to the input linked list
while(curr){
    // intitalize the prev to point to dummy ,At each iteration, we insert an element into the resulting list.
    ListNode* prev=dummy;
// if there are elements in the resulting list then check
while(prev->next && prev->next->val<=curr->val){
    // move prev pointer to the element after which we can insert the curr node
    prev=prev->next;
}

ListNode* next=curr->next;//holds the point to next element in input ll, used later to place curr
//insert the curr node to resulting list
curr->next=prev->next;
prev->next=curr;
//move to next iteration
curr=next;
}
return dummy->next;

 
    }
};