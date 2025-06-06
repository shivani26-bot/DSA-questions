class Solution {
public:

    int calPoints(vector<string>& operations) {
        int n=operations.size();
        stack<int>st;
    for(auto s: operations){

        if(s=="+"){
            if(st.size()>=2){
               int top_ele= st.top(); st.pop();
               int new_top_ele= top_ele+st.top();
               st.push(top_ele);
               st.push(new_top_ele) ;
            }
        }
    
        else if(s=="C"){
          if(!st.empty())  st.pop();
        }
        else if(s=="D"){
            if(!st.empty()) st.push(2 * st.top());
        }
        else{
              int num=stoi(s);
                  st.push(num);
        }

    }

    int total_sum=0;
       
    while(!st.empty()){
        int ele=st.top();
        st.pop();
    total_sum+=ele;
    }
    return total_sum;
    }
};