class Solution {
public:
// o(2^n)
// string inv(const string &s){
//     string result=s;
//     for(int i=0;i<result.length();i++){
//         result[i]= (result[i]=='0')?'1':'0';
//     }
//     return result;
// }
// string rev(const string &s){
//     string result=s;
//    reverse(result.begin(),result.end());
//     return result;
// }
// string f(int n){
//     if(n==1) return "0";

//   string s=  f(n-1);

//   return s+"1"+rev(inv(s));
// //   return f(n-1)+"1"+rev(inv(f(n-1)));
// }
//     char findKthBit(int n, int k) {
        
//        string s= f(n);
//        cout<<s<<endl;
//         return s[k-1];
//     }


// time:o(n)
// space: o(n) recursion stack 
// Si = Si - 1 + "1" + reverse(invert(Si - 1)) for i > 1
// see at this equation to find the current si we need to find si-1 which tells its best suited for recursion 
    char findKthBit(int n, int k) {
    //   1 2 3 4 5 6 7  -> bit
    //   0 1 1 1 0 0 1 -> original
    //   1 2 3 4 5 6 7  -> bit
    //   1 0 0 1 1 1 0 -> reversed
// 1st bit -> reverse 7th bit => (7-(1-1))
// 2nd bit -> reverse 6th bit => (7-(2-1))
// 3rd bit -> reverse 5th bit => (7-(3-1))
// original ka kth bit, reverse mein len-(k-1) ho jayega
    //   k=3, len-(k-1)
    //   7-(3-1)=5 
    //   5th bit in reversed will be equal to 3rd bit in original 
    if(n==1) return '0';
    int len= (1<<n)-1;

    if(k<ceil(len/2.0)){
        return findKthBit(n-1,k);
    }
    else if(k==ceil(len/2.0)){
        return '1';
    }
    else {
        char ch=findKthBit(n-1, len-(k-1)); //handle reversed bit
        return ch=='0'?'1':'0'; //handle flipped bit
    }
    }

    // first reverse then flip or first flip then reverse both are same
};

// n=4 k=11
// n=1  0
// n=2  0 1 1
// n=3  011 1 001
// n=4  0111001 1 0110001 here i can get the 11th bit as length is greater than 11

// there is middle parting where we append 1 at each step
// if k=3 then i will get the 3rd bit on lhs of middle element
// k< totallength/2
// left half of string in n=4 is exactly same as n=3
// for n=4 if we have to find k=3 then return the answer of n=3 , k=3
// when k<length/2 then return the answer for kth bit of n-1
// if k is exactly the middle posiition then return the middle element
