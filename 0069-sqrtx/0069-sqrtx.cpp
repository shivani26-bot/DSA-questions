class Solution {
public:
    int mySqrt(int x) {
        int num=x;
         int l=1,h=num/2;
        if(num==1) return 1;
while(l<=h){
long long mid=l+(h-l)/2;
 
 if(mid*mid<=num) l=mid+1;
 else h=mid-1;
}
return h;
    }
};