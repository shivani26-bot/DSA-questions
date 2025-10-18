class Solution {
public:
    bool isPalindrome(int x) {
        string original=to_string(x);
        string x_= to_string(x);
        reverse(x_.begin(),x_.end());
        return x_==original;
    }
};