class Solution {
public:
// signed integer means + and - both 
// Typical Ranges (on 32-bit and 64-bit systems with 32-bit int):
// INT_MIN = −2,147,483,648 → (−2³¹)
// INT_MAX = +2,147,483,647 → (2³¹ − 1)
    int reverse(int x) {
        int rev=0;

        while(x){
            //take out the last elment
            int digit=x%10;
            if(rev > INT_MAX/10 || rev < INT_MIN/10) return 0;
            rev= rev*10+ digit;
            x=x/10;
        }
        return rev;
    }
};