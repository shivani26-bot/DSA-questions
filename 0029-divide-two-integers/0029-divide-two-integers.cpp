class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend ==INT_MIN && divisor == -1){
            return INT_MAX;
        }
        long long dvd=abs(dividend);
        long long dvs=abs(divisor);
        long long result=0;
        int sign= ((dividend<0) ^ (divisor<0)) == 1 ? -1:1;
        while(dvd>=dvs){
            long long temp=dvs,mul=1;
            while(temp<<1 <= dvd){
                temp<<=1;
                mul<<=1;
            }
            dvd-=temp;
            result+=mul;
        }
        return sign*result;
    }
};