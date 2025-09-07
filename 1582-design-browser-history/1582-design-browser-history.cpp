class Node{
    public:
    // every node has data, next and prev ptr for a node 
    string data;
    Node* next;
    Node* prev;
    Node(string x){
        data=x;
        next=NULL;
        prev=NULL;
    }
    // Node (string x, Node* next, Node* prev){
    //     data=x;
    //     next=next;
    //     prev=prev;
    // }
};

class BrowserHistory {
    Node* currPage;
public:
    BrowserHistory(string homepage) {
     currPage= new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode=new Node(url);
currPage->next=newNode;
newNode->prev=currPage;
currPage=newNode;
    }
    
    string back(int steps) {
        while(steps>0){
            if(currPage->prev!=NULL){
                currPage=currPage->prev;
            }
            else{
                // no previous node
                break;
            }
            steps--;
        }

        // if steps is 0 then it means current page data; and also if while loops breaks or ends return currPage data
        return currPage->data;
    }
    
    string forward(int steps) {
         while(steps>0){
            if(currPage->next!=NULL){
                currPage=currPage->next;
            }
            else{
                // no previous node
                break;
            }
            steps--;
        }

        // if steps is 0 then it means current page data; and also if while loops breaks or ends return currPage data
        return currPage->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */