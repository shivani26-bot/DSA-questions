class Solution {
public:
    int takeCharacters(string s, int k) {
        // try to find maximum window size, such that where character a,b,c are not present>=k times
        // maximum sized window substring such that if we don't delete those
// character then we get the remaining elements which on deletion consists of
// atleast k characters of each a, b, c
// aab    aaaa       caabc
//     not deleted
//     window
//     substring
// n-notdeletedwindowsubstringsize= numberofitemsdeleted
        int n=s.length();
        unordered_map<char,int>mp;
        for(char &ch:s){
            mp[ch]++;
        }
        if(k==0) return 0;
        if(mp.size()<3) return -1;
        if(mp['a']<k || mp['b']<k || mp['c']<k) return -1;
        int not_deleted_window=0;
        int not_deleted_window_length=INT_MIN;
        int i=0,j=0;
        while(j<n){
            mp[s[j]]--;
            //shrink the window from ith side or left side
            while(i<=j && mp[s[j]]<k){
                mp[s[i]]++;
                i++;
            }
            not_deleted_window_length= max(not_deleted_window_length,j-i+1);
            j++;
        }
        return n-not_deleted_window_length;//gives deleted window size
    }
};

// brute force
// we have two possibility , either take a element from left or right
//                        aabaacabc k=2
//      abaacabc, {1,0,0}                     aabaacab, {0,0,1}
// baacabc {2,0,0}  abaacab, {1,0,1}
// o(2^n) take or not take
