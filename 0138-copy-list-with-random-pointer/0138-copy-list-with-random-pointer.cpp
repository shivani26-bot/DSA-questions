/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // using the original head, store the new node for each current node, use map for this
        Node* prev=NULL;
        Node* cloneHead=NULL;
        unordered_map<Node*,Node*>nodesMap;
        Node* curr=head;//to track the current node in the list

        while(curr){
            //make a new  node and store it in map
            Node* temp= new Node(curr->val);
            nodesMap[curr]=temp;//for the original node curr, store the new node temp, both have same value
//if its the first node then update the cloneHead;
if(!prev){
    cloneHead=temp;
    prev=temp;
}
else{
    //otherwise link the prev nodes next pointer to temp;
    prev->next=temp;
    prev=temp;
}
            curr=curr->next;
        }
        Node* curr1=head;
        Node* curr2=cloneHead;
        //now update the random pointer for each node in new linked list
        while(curr2){
            // only if random pointer exists for that in original linked list
            if(curr1->random)
              curr2->random=nodesMap[curr1->random];
            else curr2->random=NULL;

curr1=curr1->next;
curr2=curr2->next;
        }
        return cloneHead;

    }
};