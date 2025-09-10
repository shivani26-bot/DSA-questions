class MyCircularQueue {
    int k;
    int count=0;
    queue<int>q;
public:
    MyCircularQueue(int k) {
        this->k=k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;//we can't push elements if queue is already full
        q.push(value);
        count++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;//we can't remove elements if queue is already empty
        q.pop();
        count--;
        return true;
    }
    
    int Front() {
        return isEmpty()?-1: q.front();
    }
    
    int Rear() {
        return isEmpty()?-1: q.back();
    }
    
    bool isEmpty() {
        return count==0;
    }
    
    bool isFull() {
        return count==k;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */