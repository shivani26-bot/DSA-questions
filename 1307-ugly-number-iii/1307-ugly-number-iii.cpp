

class Solution {
public:
typedef long long ll;

// ll gcd(ll a, ll b) {
//     return b == 0 ? a : gcd(b, a % b);
// }

ll lcm(ll a, ll b) {
    //   return a /gcd(a, b) * b; //this also works
    return a / __gcd(a, b) * b;  // still safe as a and b are within 1e9
}
    int nthUglyNumber(int n, int a, int b, int c) {
  ll lcm_ab= lcm(a,b);
  ll lcm_ac= lcm(a,c);
  ll lcm_bc= lcm(b,c);
  ll lcm_abc=lcm(a,lcm_bc);

  //anonymous function
  auto isPossibleUglyNumber= [&](ll num){
   ll requiredUglyNumber= num/a +num/b+num/c-num/lcm_ab -num/lcm_bc -num/lcm_ac + num/lcm_abc;
    return requiredUglyNumber>=n;
  };

 ll l=1, h=2e9;
  ll result=0;
  while(l<=h){
    ll m=l+(h-l)/2;
    if(isPossibleUglyNumber(m)){
        result=m;
        h=m-1;
    }
    else{
        l=m+1;
    }
  }
  return result;
    }
};

//failed test case:
//  n=1000000000 ,a=2,b=217983653,c=336916467 i get output 1999999978 but expected output is 1999999984

//C++'s lcm() from <numeric>, which internally uses:
// lcm(a, b) = (a / gcd(a, b)) * b
// This can overflow if (a * b) exceeds 1e18, even if the final result is still within bounds (as guaranteed by the problem). With values like a = 217983653, b = 336916467, their lcm is large (~7.34e16), and multiplying again by a or b to get lcm_abc can cause undefined behavior due to overflow.
// Since C++ doesn't have built-in support for safe multiplication in all environments, here's a safer lcm version using long long

// ll lcm(ll a, ll b) {
//     return a / __gcd(a, b) * b; 
// }


// n=100, a=2, b=3, c=5
// All numbers divisible by 2 from 1 to 100:
// 2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,82,84,86,88,90,92,94,96,98,100
// (50 numbers in total)

// All numbers divisible by 3 from 1 to 100:
// 3,6,9,12,15,18,21,24,27,30,33,36,39,42,45,48,51,54,57,60,63,66,69,72,75,78,81,84,87,90,93,96,99
// (33 numbers in total)

// All numbers divisible by 5 from 1 to 100:
// 5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100
// (20 numbers in total)

// Divisible by both 2 and 3 (LCM = 6):
// All numbers divisible by 6 from 1 to 100:
// 6,12,18,24,30,36,42,48,54,60,66,72,78,84,90,96
// (16 numbers in total)

// Divisible by both 3 and 5 (LCM = 15):
// All numbers divisible by 15 from 1 to 100:
// 15,30,45,60,75,90
// (6 numbers in total)

// Divisible by both 2 and 5 (LCM = 10):
// All numbers divisible by 10 from 1 to 100:
// 10,20,30,40,50,60,70,80,90,100
// (10 numbers in total)

// Divisible by All Three Numbers (2, 3, and 5) (LCM = 30)
// All numbers divisible by 30 from 1 to 100:
// (3 numbers in total)