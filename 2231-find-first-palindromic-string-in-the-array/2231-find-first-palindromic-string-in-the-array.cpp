class Solution {
public:
// o(n)
//two pointer
// bool isPalindrome(string s){
//     int n= s.length();
//     int i=0, j=n-1;
//     while(i<j){
//         if(s[i]!=s[j]) return false;
//         else{
//             i++;
//             j--;
//         }
//     }
//     return true;
// }
// o(n^2)
    // string firstPalindrome(vector<string>& words) {
    //     // o(n)
    //     for(int i=0;i<words.size();i++){
    //         if(isPalindrome(words[i])) {
    //             return words[i];
    //             break;
    //         }
    //     }
    //     return "";
    // }



     string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
          string reversed=words[i];
          reverse(reversed.begin(),reversed.end());
          if(words[i]==reversed){
            return words[i];
          }
        }
        return "";
    }
};