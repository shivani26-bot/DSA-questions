class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // 01234
        // abcba
        // 013  014
        // aba, aba will be counted once
        // 3 length of palindrome
        // X   X  we can place any character in middle but same characters at ends
        // _ _ _
         
        //  we can store characters in set, start giving chance to each character one by one
        //  s="abcab"
        //  aba
        //  aca
        //  bcb
        //  bab
        //  set={a,b,c}
        //  start with charater a, check the index of a in s, i=0, j=3
        //  can we make palindrome using character between i+1 and j-1,
        //  we have two unique characters b and c set= {b,c}
        //  next start with character b and then c
        int n=s.length();
       set<char>letters(s.begin(),s.end());

       int uniquePalindrome=0;
       for(auto letter: letters){
        // find first most and last most index of that letter
        int left_idx=-1;
        int right_idx=-1;
        for(int i=0;i<n;i++){
            if(s[i]==letter){
               if(left_idx==-1) left_idx=i;
             right_idx=i;

            }
        }
        set<char>st;
        for(int middle=left_idx+1;middle<right_idx;middle++){
            st.insert(s[middle]);
        }
        uniquePalindrome+=st.size();


       }



return uniquePalindrome;

    }
};