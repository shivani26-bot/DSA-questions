class Solution {
public:
    // string mergeAlternately(string word1, string word2) {
    //     int n=word1.size(),m=word2.size();
    //     bool flag=false;
    //     int i=0,j=0;
    //     string newStr="";
    //     while(i<n || j<m){
    //         if(!flag){
    //              flag=true;
    //             if(i>=n) continue;
    //             newStr+=word1[i];
    //             i++;
               
    //         }
    //         else{
    //                flag=false;
    //                     if(j>=m) continue;
    //             newStr+=word2[j];
    //             j++;
             
    //         }
    //     }
    //     return newStr;
    // }

        string mergeAlternately(string word1, string word2) {
        int n=word1.size(),m=word2.size();
int k=min(n,m);//shortest length;
int i=0;
string newStr="";
while(i<k){
    newStr+=word1[i];
    newStr+=word2[i];
    i++;
}
if(n>m){
    newStr+= word1.substr(k);
}
if(m>n){
    newStr+= word2.substr(k);
}
return newStr;
    }
};