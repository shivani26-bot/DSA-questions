class MyStack {
      queue<int>q;
public:
    MyStack() {
      
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        queue<int>temp;
        while(q.size()>1){
            temp.push(q.front());
            q.pop();
        }
        int ans=q.front();
        q.pop();
        q=temp;
        return ans;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */