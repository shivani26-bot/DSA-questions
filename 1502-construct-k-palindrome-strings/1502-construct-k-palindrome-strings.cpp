class Solution {
public:
    bool canConstruct(string& s, int k) {
        int n=s.length();
        if(n==k) return true;
        if(n<k) return false;
        // number of maximum possible palindromes= length of string
        // abcd=> a, b, c ,d every character in itself is a palindrome
        // even number wale characters easily distribute ho jayenge
        // problems wo characters create krenge jinki occurence odd number
        // of time hogi
        // aabbccddee k=3
        // each character occurs ever number of times
        // atmost possible palindromes=10
        // dcbaabcd, e, e
        // k=2 dcbaabcd, ee
        // k=1 edcbaabcde
        // odd freq character??
        // ababcx k=3
        // abba, c, x
        // k=2
        // abcba, x or abxba, c
        // k=1 not possible
// number of characters with odd frequency <= k , we can make palindromes
// but if number of character with odd frequency >k , we can't make palindromes
    map<char,int>mp;
    // s,k
    for(int i=0;i<n;i++){
        mp[s[i]]++;
    }
    int countOddFreqChar=0;
    for(auto it: mp){
        if(it.second%2)
        countOddFreqChar++;
    }
    return countOddFreqChar<=k;
    }
};