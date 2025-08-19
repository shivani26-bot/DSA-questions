class Solution {
public:
// bool matchesPattern(string& num, string &pattern){
//     int n=pattern.size();
//     for(int i=0;i<n;i++){
//         if(pattern[i]=='I' && num[i]>=num[i+1]) return false;
//         else if(pattern[i]=='D' && num[i]<num[i+1]) return false;
//     }
//     return true;
// }
    string smallestNumber(string pattern) {
//         Input: pattern = "IIIDIDDD"
// Output: "123549876" (lexicographically smallest)
// other possible answers are 245639871,135749862
// brute force: create all lexicographically smallest permutations, check if it follows the  pattern 
// c++ utility: next_permutation() : ensures that permutation is generated lexicographically
// if pattern length is n, then result lenght will be n+1
// permutation of n+1 digits (n+1)!*o(n), for every permutation check if its the valid answer or not 
// sc=o(n)
// int n=pattern.length();//n=3
// string num="";
// for(int i=1;i<=n+1;i++){
//     num.push_back(i+'0');//convert integer to char
// }
// //num="1234"
// while(!matchesPattern(num,pattern)){
//     next_permutation(begin(num),end(num));
// }
// return num;


// 2nd approach: 
// "I I I D D D D D"
//  1 2 3 4
//  1 2 3 5 4
//  1 2 3 6 5 4
//  1 2 3 7 6 5 4
//  1 2 3 8 7 6 5 4
//  1 2 3 9 8 7 6 5 4

//  "I I I D"
//   1 2 3 4
//   1 2 3 5 4

//   "I I I D D"
//    1 2 3 4 
//    1 2 3 5 4
//    1 2 3 6 5 4

// maintain a count 
// assign and increase count value if its 'I', increase count value if it's 'D'
// once outof bound assign the value in reverse order
// " I I I D D D D D"
//   1 2 3 9 8 7 6 5 4
// count=1 2 3 4 5 6 7 8 9

//     "I I I D I D D D"
// num- 1 2 3 5 4 9 8 7 6
// count= 1 2 3 4 5 6 7 8 9
// push count in stack, if 'I' then pop the top element, if'D'
//  then store in stack, once outofbound pop the element from stack
//  stack= 1 
//   stack= 2
//    stack= 3
//     stack= 4 5
//      stack= 6 7 8 9
//      stack = empty
//      we pop the element from the stack when encounters 'I' or reaches n+1  
// o(n) every element is visited once 
// sc: o(n+1) stack is used here
stack<char>st;
int counter=1;
string result;
int n=pattern.size();
for(int i=0;i<=pattern.size();i++){
    st.push(counter+'0');
    counter++;
    if(i==n || pattern[i]=='I'){
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }
    }
}
return result;
    }
};