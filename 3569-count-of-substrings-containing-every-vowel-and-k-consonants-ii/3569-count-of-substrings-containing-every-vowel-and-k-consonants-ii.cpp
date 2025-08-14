class Solution {
public:
long long atleastK(string word,int k){
        //  You need the number of consonants to be exactly k, no more, no less.
        int n=word.length();
        int i=0,j=0;
        long countSubstr=0;
        unordered_map<char,int>vowel;
        int consonantCount=0;
        while(j<n){
            if(word[j]=='a'|| word[j]=='e' || word[j]=='i'||word[j]=='o'||word[j]=='u')
            vowel[word[j]]++;
            else consonantCount++;
          
   
while(vowel.size()==5 && consonantCount>=k){
                     countSubstr+=(n-j);
if(word[i]=='a'|| word[i]=='e' || word[i]=='i'||word[i]=='o'||word[i]=='u')
           { 
            vowel[word[i]]--;
            if(vowel[word[i]]==0) vowel.erase(word[i]);
            }
            else {
                consonantCount--;
                }
i++;
                }
              
            j++;
       
        
        }
        return countSubstr;
}
    long long countOfSubstrings(string word, int k) {

        return atleastK(word,k)-atleastK(word,k+1);
    }
};