class MyLinkedList {

   private class Node{
    int val;
    Node next;

    Node(int val){
        this.val=val;
    }
   }

private Node sentinel;
private int size;
    public MyLinkedList() {
        sentinel=new Node(0);
        size=0;
        
    }
    
    public int get(int index) {
        if(index<0 || index>=size) return -1;
        Node curr=sentinel.next;
        for(int i=0;i<index;i++){
            curr=curr.next;
        }
        return curr.val;
        
    }
    
    public void addAtHead(int val) {
        addAtIndex(0,val);
    }
    
    public void addAtTail(int val) {
        addAtIndex(size,val);
    }
    
    public void addAtIndex(int index, int val) {
        if(index<0 || index>size) return;
        Node pred=sentinel;
        for(int i=0;i<index;i++){
            pred=pred.next;
        }
        Node newNode= new Node(val);
        newNode.next=pred.next;
        pred.next=newNode;
        size++;
    }
    
    public void deleteAtIndex(int index) {
        if(index<0 || index>=size) return;
        Node pred=sentinel;
        for(int i=0;i<index;i++){
            pred=pred.next;

        }
        pred.next=pred.next.next;
        size--;
        
    }
}