class MinStack {
    stack<int>st;
public:
    MinStack() {

    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        int minEle=INT_MAX;
        stack<int>temp=st;
        while(!temp.empty()){
            int ele=temp.top();
              minEle=min(minEle, ele);
        temp.pop();
          
        }
        return minEle;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */