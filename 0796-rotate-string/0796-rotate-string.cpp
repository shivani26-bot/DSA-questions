class Solution {
public:
    bool rotateString(string s, string goal) {
//    for a given string we can rotate it for n(size of s) number of times
    // abc
    // bca
    // cab
    // abc
    int n=s.length();
    // rotate(start of range, which possition will become starting position, end of range)

    for(int count=1;count<=n;count++){
       rotate(s.begin(),s.begin()+1,s.end());
       if(s==goal) return true;

    }
    return false;
    }
};