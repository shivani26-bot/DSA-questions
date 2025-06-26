class Solution {
public:
    int calculate(string s) {
        // evaluate from left to right and evaluation depends on the Operator Precedence
        // + - * / , without paranthesis */ has highest priority than -+
    stack<int>st; //stores the operand, in integer form


    int n=s.length();
    int currNumber=0;
    char prevOperation='+';//very first character in string, for it the prevOperation will be +
    for(int i=0;i<n;i++){
        int currChar=s[i];
        if(isdigit(currChar)) currNumber=currNumber*10+(currChar-'0');
        //for last character as well, last character in string will always be a digit
     if(!isdigit(currChar) && !iswspace(currChar)||i==n-1){
       if(prevOperation=='-'){
        st.push(-currNumber);
       }
       else if(prevOperation=='+'){
        st.push(currNumber);
       }
       else if(prevOperation=='*'){
        int a=st.top();
        st.pop();
        st.push(a*currNumber);
       }
       else if(prevOperation=='/'){
        int a=st.top();
        st.pop();
        st.push(a/currNumber);
       }

prevOperation=currChar;
currNumber=0;
     }
    }

int result=0;
while(!st.empty()){
    result+=st.top();
    st.pop();
}
return result;
    }
};