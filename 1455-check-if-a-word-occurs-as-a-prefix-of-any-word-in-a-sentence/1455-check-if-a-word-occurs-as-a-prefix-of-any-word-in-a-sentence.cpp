class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int count=1;
        int n=sentence.length();
        int  m=searchWord.length();
        int i=0,j=0;
        while(i<n){
            if(sentence[i]==' '){
                count++;
                i++;
            }
            // if(sentence[i]!=searchWord[j]) i++;
                     if(sentence[i]!=searchWord[j]){
                        while(i<n&& sentence[i]!=' ') i++;
                     }
            cout<<i<<endl;
            while(j<m && sentence[i]==searchWord[j]){
                 cout<<i<<" "<<j<<endl;
                j++;
                i++;
                cout<<i<<" "<<j<<endl;
            }
            cout<<j<<" " <<m<<endl;
            if(j==m) return count;
            if(j<m) j=0;
        }
        return -1;
    }
};