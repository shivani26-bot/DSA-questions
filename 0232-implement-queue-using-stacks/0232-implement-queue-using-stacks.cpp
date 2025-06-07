// class MyQueue {
//     stack<int>st;
// public:
//     MyQueue() {
        
//     }
    
//     void push(int x) {
//         st.push(x);
//     }

//     void pushBottom(stack<int>&temp,int ele){
//         if(temp.empty()){
//             temp.push(ele);
//             return ;
//         }
//         int popped_ele= temp.top();
//         temp.pop();
//         pushBottom(temp,ele);
//        temp.push(popped_ele);
//     }

//     int pop() {
//         stack<int>temp;
//         while(st.size()>1){
//             pushBottom(temp,st.top());
//             st.pop();
//         }
//         int ans=st.top();
//         st.pop();
//         st=temp;
//         return ans;
//     }
    
//     int peek() {
//           stack<int>temp;
//         while(st.size()>1){
//             pushBottom(temp,st.top());
//             st.pop();
//         }
//         int ans=st.top();
//         pushBottom(temp,st.top());
//             st.pop();
//         st=temp;
//         return ans;
//     }
    
//     bool empty() {
//         return st.empty();
//     }
// };



class MyQueue {
stack<int>s1,s2;

public:
    MyQueue() {}
//s1 will store the elements in queue fashion, 
    void push(int x) {
      while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
      }
      s1.push(x);
         while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
      }

    }

    int pop() {
      int ans= s1.top();
      s1.pop();
      return ans;
    }

    int peek() {
        return s1.top();
    }

    bool empty() {
       return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */