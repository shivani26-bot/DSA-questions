class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        // first check if both the strings are equal or not 
        // if both strings are equal it means 0 swap 
        // if(s1==s2) return true;
        // // we can maitain the freqency of each character 
        // vector<int>s1Freq(26,0);
        // vector<int>s2Freq(26,0);
        // int numDiff=0;
        // // iterate through the strings, both the string must be of same size
        // // in order to have only 1 swap, only 2 elements in s1 s2 will be at wrong posiition or will not match, and rest of the elements in s1 and s2 are at same position and will match at same index
        // for(int i=0;i<s1.size();i++){
        //     if(s1[i]!=s2[i]){
        //         // increase the numdiff
        //         numDiff++;
        //         if(numDiff>2) return false; //it means more than 2 elements are at wrong position
        //     }
        //     s1Freq[s1[i]-'a']++;
        //     s2Freq[s2[i]-'a']++;
        // }

        // // at last check whether both s1 and s2 are anagrams or freq of each elemnt in them are same 
        // for(int i=0;i<26;i++){
        //     if(s1Freq[i]!=s2Freq[i])  return false;
        // }
        // return true;


        // we can track the index when numdiff is 1 and numdiff is 2 and at last check leemnts at those indexes are equal or not 
        int firstIdx=0,secondIdx=0;
        int numDiff=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                numDiff++;
                if(numDiff>2) return false;
                else if(numDiff==1){
                    // store the first index where elements are different 
                    firstIdx=i;
                }
                else{
                    //when numdiff is 2
                    // store the second index where elements are different 
                    secondIdx=i;
                }
            }
        }
        return s1[firstIdx]==s2[secondIdx] && s1[secondIdx]==s2[firstIdx];

    }
};