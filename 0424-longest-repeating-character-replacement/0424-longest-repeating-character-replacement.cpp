// class Solution {
// public:
//     int characterReplacement(string s, int k) {
// //         int n=s.length();
// //         int i=0,j=0;
// //         unordered_map<char,int>mp;
// // int maxWin=INT_MIN;
// // int maxRepeatCharInWin=0;
// //         while(j<n){
// //             mp[s[j]]++;
// //             int currLen=j-i+1;
// //             maxRepeatCharInWin=max(mp[s[j]],maxRepeatCharInWin);
// //             if(abs(currLen-maxRepeatCharInWin)>k){
// //                 mp[s[i]]--;
// //                 if(mp[s[i]]==0) mp.erase(s[i]);
// //                 i++;
// //             }
// //             currLen=j-i+1;
// //             maxWin=max(maxWin,currLen);
// //             j++;
// //         }
// //         return maxWin;
//        int n=s.length();
//         int i=0,j=0;
//         unordered_map<char,int>mp;
// int maxWin=INT_MIN;
// int maxRepeatCharInWin=0;
//         while(j<n){
//             mp[s[j]]++;
//             int currLen=j-i+1;
//             maxRepeatCharInWin=max(mp[s[j]],maxRepeatCharInWin);
//             if(abs(currLen-maxRepeatCharInWin)>k){
//                 mp[s[i]]--;
//                 if(mp[s[i]]==0) mp.erase(s[i]);
//                 i++;
//             }
//             currLen=j-i+1;
//             maxWin=max(maxWin,currLen);
//             j++;
//         }
//         return maxWin;
//     }
// };

class Solution {
public:
    int characterReplacement(string s, int k) {
//         int n=s.length();
//         int i=0,j=0;
//         unordered_map<char,int>mp;
// int maxWin=INT_MIN;
// int maxRepeatCharInWin=0;
//         while(j<n){
//             mp[s[j]]++;
//             int currLen=j-i+1;
//             maxRepeatCharInWin=max(mp[s[j]],maxRepeatCharInWin);
//             if(abs(currLen-maxRepeatCharInWin)>k){
//                 mp[s[i]]--;
//                 if(mp[s[i]]==0) mp.erase(s[i]);
//                 i++;
//             }
//             currLen=j-i+1;
//             maxWin=max(maxWin,currLen);
//             j++;
//         }
//         return maxWin;
       int n=s.length();
        int i=0,j=0;
        unordered_map<char,int>mp;
int maxWin=INT_MIN;
int maxRepeatCharInWin=0;
        while(j<n){
            mp[s[j]]++;

            maxRepeatCharInWin=max(mp[s[j]],maxRepeatCharInWin);
            while(abs((j-i+1)-maxRepeatCharInWin)>k){
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
            }
 
            maxWin=max(maxWin,j-i+1);
            j++;
        }
        return maxWin;
    }
};