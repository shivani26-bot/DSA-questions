
// class Solution {
// public:
// for each token, we either perform a constant time operation 
// (such as checking if it is a number) or recursively call the evalRPN function on a smaller input vector
// time :o(n)
// space: o(n)
    // int evalRPN(vector<string>& tokens) {
    //     string token=tokens.back();
    //     tokens.pop_back();
    //     if(token!="*" && token!="/" && token!="+" && token!="-" )
    //     return stoi(token);
    //     else
    //     {
    //         long long a= evalRPN(tokens);
    //         long long b= evalRPN(tokens);
    //         if(token=="+") return b+a;
    //         else if(token=="-") return b-a;
    //         else if(token=="/") return b/a;
    //         else return b*a;
    //     }
    // }
// bool isOperator(string &token){
//     if(token=="+"||token=="-"||token=="/"||token=="*") return true;
//     else return false;
// }
// int evaluate(int a,int b, string &token){
//     if(token=="+") return b+a;
//     if(token=="-") return b-a;
//     if(token=="*") return b*a;
//     if(token=="/") return b/a;
//     return 0;
    
// }
//     int evalRPN(vector<string>& tokens) {
//       stack<int>st;
//       for(auto token: tokens)
//       {
//           if(isOperator(token)){
//                int a=st.top();
//                st.pop();
//                int b=st.top();
//                st.pop();
//                st.push(evaluate(a,b,token));
//           }
//           else{
//               st.push(stoi(token));
//           }
//       }
//       return st.top();
//     }
// };
class Solution {
public:

int evaluate(int a, int b, string& token){
    if(token=="+") return b+a;
     if(token=="-") return b-a;
      if(token=="*") return b*a;
       if(token=="/") return b/a;
       return 0;
}

    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            if(tokens[i]=="*" ||tokens[i]=="/"||tokens[i]=="+"||tokens[i]=="-" ){
                int a=st.top(); st.pop();
                int b=st.top();st.pop();
                st.push(evaluate(a,b,tokens[i]));
            }
else
            st.push(stoi(tokens[i]));
        }
        return st.top();
    }
};