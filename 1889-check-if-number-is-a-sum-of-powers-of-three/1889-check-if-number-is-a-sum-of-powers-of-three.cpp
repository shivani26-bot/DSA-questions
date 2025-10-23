class Solution {
public:
    bool checkPowersOfThree(int n) {
        // sum of distinct powers of three
        // we cannot use 3^0+3^0......
        // n=12
        // max power we can use to reach 12
        // 3^0=1  3^1=3 3^2=9 3^3=27
        // max power =2 because 3^2=9
        // 12-9=3, we cannot use power 2 again
        // 3-3^1=0 it's possible
        // n=6
        //         max power we can use to reach 6
        // 3^0=1  3^1=3 3^2=9 
        // max power=1
        // 6-3^1=3
        // 3 is still >= 3^1=3 but we cannot use power 1 again
        // 3-3^0=2 it's not possible
        // n=21
        //  max power we can use to reach 21
        // 3^0=1  3^1=3 3^2=9 3^3=27
        //         max power =2 because 3^2=9
        // 21-3^2=21-9=12 //if still greater than current power of 3 ie 3^2 return false
        // 12>=3^2 but we cannot use same power again
// find the max power 
// int p=0;
// // untill the power of 3 < n increment p 
// while(pow(3,p)<n){
//     p++;
// }
//  while(n>0){
//     if(n>=pow(3,p)){
//         n=n-pow(3,p);
//     }
//     // even after subtracting n is > current power of 3 return false;
//     if(n>=pow(3,p)) return false;
//     p--;
//  }
// return true;

// binary representation of 15
// divide the number by 2 continuously and write the remainder as ans
// 2|15|1
// 2|7|1
// 2|3|1
// 2|1|1
//   0
// 15= 0 1 1 1 1
// we can convert binary to decimal
// (0*2^4) + (1*2^3) +(1*2^2) +(1*2^1) + (1*2^0)
// n= (dk*2^k) +  (dk-1*2^k-1) + ..... + (d0*2^0) 
// how many time a power will be used, 2^3 will be used 1 time
// similarly ternary representation, divide by 3
// n=12
// 3|12|0
// 3|4|1
// 3|1|1
//   0
// 13=0110
// n= (dk*3^k) +  (dk-1*3^k-1) + ..... + (d0*2^0) 
// 12= (0*3^3) + (1*3^2) +(1*3^1) +(0*3^0) 

// n=21
// 3|21|0
// 3|7|1
// 3|2|2
//   0
// 21=0210
// 21=(0*3^3) + (2*3^2) +(1*3^1) +(0*3^0) 
// here 3^2 is coming 2 times hence ans is false
// if we have other than 0 or 1 it is false
// x%3=0/1/2 if its 2 then false

// log3n because we are dividing by 3
while(n>0){
    if(n%3==2) return false;
    n=n/3;
}
return true;
    }
};