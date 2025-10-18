class Solution {
public:
    bool isPalindrome(int x) {
        // string original=to_string(x);
        // string x_= to_string(x);
        // reverse(x_.begin(),x_.end());
        // return x_==original;

        // if number is less than 0 it can never be palindrome because - will come in end 
        if(x<0) return false;

        // only run a logic for x>0 
        // find the reverse of a number 
        int num=x;
        long long rev=0;
        while(num){
            rev=rev*10+num%10;
            num=num/10;
        }
        return x==rev;
    }
};