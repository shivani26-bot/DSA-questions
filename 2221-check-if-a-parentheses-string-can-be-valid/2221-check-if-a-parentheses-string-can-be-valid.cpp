class Solution {
public:
// s="())(()(("
// locked="10001111"

// normally in order to check valid parenthesis, we stor open brackets in stack and for every close bracket we pop the open bracket in stack, in end we check whether stack is empty or not, if empty we return true that it's a valid parenthesis string otherwise return false

// but here we have locked string
// for locked[i]=1, we will follow our normal algorithm, 
// but for locked[i]=0 we will store them in another stack
// also store indices of brackets here, as it will be helpful
//            0  1  2  3  4  5  6  7
// s=        "(  )  )  (  (  )  (  (  "
// locked="   1  0  0  0  1  1  1  1"
// openstack= 0 4
// openstack= 0 6 7
// openclose= 1 2 3
// for open bracket at index 7 we want a closing bracket at index greater than 7 but openclose stack has smaller index at top
// return false here
//         0  1  2  3  4  5
// s=     ")  )  (  )  )  )"
// locked="0  1  0  1  0  0
// openstack=
// openclose= 0 
// if locked[i]=1 and s[i]=) then it will first check with openstack, if it's empty
// it will check with openclose stack, if index in openclose stack is less than index=1 then it will pop
// the top element from openclose stack
// openstack=
// openclose= 2
// openstack=
// openclose= 4 5
// if openstack is empty, it means, no open bracket is left which needs to be matched with any close bracket
// openclose stack will always remain even , because total length of s must be even
// return true here

// locked[i]=0 then store index in openclose stack
// otherwise locked[i]=1 then
// if s[i]='(' push in openstack
//        ')' search in openstack first, if not present here then search into openclose stack
// if not present in openclose stack then it will be false

    bool canBeValid(string s, string locked) {
        int len=s.length();
        if(len<2 || len%2!=0) return false;
        stack<int>openClose,open;
       for(int i=0;i<len;i++){
        if(locked[i]=='0') openClose.push(i);
        else if(s[i]=='(') open.push(i); //locked[i]=1
        else if(s[i]==')'){ //locked[i]=1 
            if(!open.empty()) open.pop();
            else if( !openClose.empty()) openClose.pop();
           else return false;
        }
        
       }

       //there can be case when both the stack will be non empty
       while(!open.empty() && !openClose.empty() && open.top()<openClose.top()){
        open.pop();
        openClose.pop();
       }
     
       return open.empty();
    }
};