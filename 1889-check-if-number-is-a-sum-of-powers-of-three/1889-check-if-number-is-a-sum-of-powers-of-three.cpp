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
int p=0;
// untill the power of 3 < n increment p 
while(pow(3,p)<n){
    p++;
}
 while(n>0){
    if(n>=pow(3,p)){
        n=n-pow(3,p);
    }
    // even after subtracting n is > current power of 3 return false;
    if(n>=pow(3,p)) return false;
    p--;
 }
return true;
    }
};