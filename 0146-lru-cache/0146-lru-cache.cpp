class Node {
    public:
    int key,value;
    Node* prev,*next;
    //doubly linked list
    Node(int k,int v){
        key=k;
        value=v;
        prev=NULL;
        next=NULL;
    }
};
class LRUCache {
public:
// maintain a map to store the key and address of node containing (key,value) pair 
unordered_map<int,Node*>keyToAddress;
// maintain a currSize of the cache 
int currSize;
int maxSize;
Node* head;Node* tail;
    LRUCache(int capacity) {
        // initialize;
        maxSize=capacity;
        currSize=0;
        // INITIALLY EMPTY
        head=NULL;
        tail=NULL;
    }

    // return the node after adding to tail
    Node* addToTail(int key,int value){
//make a node to insert
Node* temp=new Node(key,value);
if(!tail){
// if first node then head and tail points to same node
head=temp;tail=temp;
}else{
    // if not the first node then attatch the new node to tail and move the tail to new node
tail->next=temp;
temp->prev=tail;
tail=temp;
}
// increas the curr size of the list
currSize++;
return temp; 
    }

//move to node and update the value to the new value
    void moveToTail(Node* node, int value){
        node->value= value;
        if(node==tail) return ;
        if(node==head){
            head=head->next;
            head->prev=NULL;
        }
        else{
            node->prev->next=node->next;
            node->next->prev=node->prev;
        }
        node->prev=tail;
        node->next=NULL;
        tail->next=node;
        tail=node;

    }
    void deleteHead(){
        Node* temp=head;
        head=head->next;
if(head){
    head->prev=NULL;
}
else tail=head;
delete(temp);
currSize--;
    }
    int get(int key) {
        int ans;
        //if key is not present in the map the ans will be -1
        if(keyToAddress.find(key)==keyToAddress.end()) return -1;
      
        else{
            Node* temp=keyToAddress[key]; //reach the node using map, as map stores the address of node for that key and retrieve the value from that node
            ans=temp->value;
            moveToTail(temp, temp->value);
        }
        return ans;
    }
    
    void put(int key, int value) {
        // first check its present in map or not, if present then update the value for exisiting key
        if(keyToAddress.find(key)!=keyToAddress.end()){
            // move to the node and update the value
            moveToTail(keyToAddress[key],value);
            return;
        }
        // if currsize is <maxSize then only add node otherwise first delete the least recently used key ie the head node, because most recently node will be added to the end of the linked list 
        if(currSize<maxSize){
            // add the node and store the node corresponding to key in map 
            keyToAddress[key]=addToTail(key,value);
        }
        else{
            // erase the head node from map then delete the head and then add the new node to tail
            keyToAddress.erase(head->key);
            deleteHead();
            keyToAddress[key]=addToTail(key,value);

        }

        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */