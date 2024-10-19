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
    char findKthBit(int n, int k) {
    //   1 2 3 4 5 6 7  -> bit
    //   0 1 1 1 0 0 1 -> original
    //   1 2 3 4 5 6 7  -> bit
    //   1 0 0 1 1 1 0 -> reversed

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
};