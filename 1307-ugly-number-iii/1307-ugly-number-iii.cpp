

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