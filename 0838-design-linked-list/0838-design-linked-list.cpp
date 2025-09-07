class Node{
    public:
    // every node has val and next pointer 
    int data;
    Node* next;
    Node (int val){
        data=val;
        next=NULL;
    }
};

// Arrays aur Linked Lists dono data structures elements store karte hain, but dono ke apne limitations hote hain.
// Arrays me size fix hota hai aur middle me insert/delete karna costly (O(n)) ho jata hai.
// Linked List ek dynamic structure hai jisme har node next node ka pointer store karta hai. Isse hum efficiently insert/delete kar sakte hain agar hume node ka reference pata ho.
class MyLinkedList {
public:
Node* head;//points to head of the ll
Node* tail;//points to tail of the ll
int size;//keeps track total nodes
    MyLinkedList() {
        //empty, only initializes
       head=tail=NULL;
       size=0;
    }
    
    int get(int index) {
        if(index<0 || index>=size) return -1;
        //if index==0 return the heads data
        if(index==0) return head->data;
        //if last node then return tails data
        if(index==size-1) return tail->data;

        Node* temp=head;
        //traverse until u reach the index
        for(int i=0;i<index;i++){
temp=temp->next;
        }
        return temp->data;
    }
    
    void addAtHead(int val) {
       Node* newNode=new Node(val);
       //if there is no node
       if(size==0){
        head=tail=newNode;//both will point to same node;

       }
       else{
        // if there is already head node 
        newNode->next=head;
        head=newNode;
       }
       size++; //increase the size of ll
    }
    
    void addAtTail(int val) {
        Node* newNode=new Node(val);
        if(size==0){// if there is no node 
            head=tail=newNode; 
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index<0 || index>size) return;
        if(index==0){
            // add at head;
            addAtHead(val); return;
        }
        if(index==size){
            //add at tail;
            addAtTail(val); return;
        }
        //if its not the first and last node then do this
        Node* newNode= new Node(val);
        Node* temp=head;
        for(int i=0;i<index-1;i++){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
        size++;//increase the size after adding the node
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>=size) return;
        if(index==0){
            //delete head;
            Node* temp=head;
            //move the head to next node
            head=head->next;
            //delete the previous head as temp
            delete temp;
            if(size==1) tail=NULL;//if while deleting the head node, we get to know that size was only 1 then it means we delete the only node it means tail should also point to null
        }else{
            Node* temp=head;
            //traverse and reach the index to delete
            for(int i=0;i<index-1;i++){
                temp=temp->next;
            }
            Node* remove=temp->next;
            temp->next=temp->next->next;
            delete remove;
            if(index==size-1) tail=temp; //if while deleting we get to know that index is size-1, that we are deleting the last node then shift the tail to temp that points to prev node to the node to be deleted
        }
        size--; //decrease the size after removing the node
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */