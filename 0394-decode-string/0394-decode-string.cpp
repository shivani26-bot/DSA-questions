class Solution {
public:
    string decodeString(string s) {
        
// 2[a3[c2[x]]y]=>2[a3[cxx]y]=> 2[acxxcxxcxxy]=>acxxcxxcxxyacxxcxxcxxy
// naive: traverse the string find the innermost bracket
    //   replace the string, repeat this every time after replacing
    // again traverse the string find the innermost bracket and so on
  
//   optimal approach: use two stack, one for storing the digits and other for storing the alphabets
// maintain two variables, number for digits and alpha for alphabets
// if current char is [ it means number and alpha till that should be stored in their
// respective stacks, and initialized to number=0, alpha="";
// if current char is ] it means we have found our first [] we should pop from both the stacks, maintain a temp string which will store the alpha, and alpha will store the st.top() and while count-->0 we will add the temp to alpha, count is the digit from the stack
// return sb as answer in end 

stack<int>digits;
stack<string>words;

int num=0;
string alpha="";

for(char c: s){
    if(isdigit(c)){
        num=num*10+ (c-'0');
    }
    else if(c=='['){
        digits.push(num);
        num=0;
        words.push(alpha);
        alpha="";
        }
        else if(c==']'){
            int count=digits.top();
            digits.pop();
            string temp=alpha;
            alpha=words.top();
            words.pop();
            while(count-->0){
               alpha+=temp;
            //    count--;
            }
        }
        else{
            alpha+=c;
        }
    }

return alpha;
    }
};