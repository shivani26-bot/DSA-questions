/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
stack<int>st;
    NestedIterator(vector<NestedInteger> &nestedList) {
        //make  a function to push nested element and integer from nestedlist vector into stack
        ListToInteger(nestedList);
    }
    void ListToInteger(vector<NestedInteger> &nestedList){
//if we iterate in forward direction from 0 to n-1 we will get answer in reversed form
        for(int i =nestedList.size()-1;i>=0;i--){
            auto curr=nestedList[i];
            if(curr.isInteger()){
                st.push(curr.getInteger());
            }
            else{
                //recursively call, because getList return nested array
                ListToInteger(curr.getList());
            }
        }

    }
    
    int next() {
        if(!st.empty()){
            int x= st.top();
            st.pop();
            return x;
        }
        return 0;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */