class Solution {
public:
double solve(double x, long n){
// time: o(logn) because n is n,n/2,n/4
    if(n==0) return 1;
if(n<0){
    return solve(1/x,-n);
}
if(n%2==0){
    return solve(x*x,n/2);
}
else return x*solve(x*x,(n-1)/2);
}
    double myPow(double x, int n) {
//         when n is even
//         x^8=> x*x*x*x*x*x*x*x
//         or it can be written as (x^2)^4
//         pow(x,n)= pow(x*x, n/2) ie pow(x*x, n/2)
// when n is odd
//         x^9 pow(x,9)
//         can be written as x*x^8
//        x*pow(x,8)=> x*pow(x*x,8/2) ie x*pow(x*x, (n-1)/2)

// when n<0
// x^-8=> (1/x)^8
// pow(x,n)=>(n<0)
// pow(1/x,-n)  -n will make the power positive 
// n<0, n=INT_MIN ie -2147483648
// and range is  -2^31 <= n <= 2^31-1
// 2^31-1 =2147483647
// if we use pow(1/x,-n)
// then n will be +2147483648 and it will over flow because positive value restricts till 2147483647, use long in such case
// 32 bits, from 0 to 31 bits, msb bit ie 31st bit is reserved for sign flag 0-> positive, 1->negative
// we are left with 31 position at every position we have 2 option either 0 or 1
// ie 2^31 possible numbers can be formed, either positive or negative
// 2^31 negative numbers which includes -1, -2,-3....,-2^31
// 2^31 -1 posiitve numbers which includes 0,1,2 3 4....2^31 -1

// anything which power as 0 results in 1 
return solve(x,long(n));


        // if(n==0) return 1;
        // // if(n==1) return x;
        // if(n>0){
        // double ans= myPow(x,n/2);
        // if(n%2==0) return ans*ans;
        // else
        // return ans*ans*x;
        // }
        // else{
        //     n=abs(n);
        //      double ans=1/(myPow(x,n/2));
        // if(n%2==0) return ans*ans;
        // else
        // return ans*ans*(1/x);
        // }
    }
};