

class Solution {
public:
typedef long long ll;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;  // still safe as a and b are within 1e9
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
