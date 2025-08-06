class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // fixed length sliding window 
        map<char,int>mp1;//will store s1 character
        map<char,int>mp2;//will sotre s2 charater
        int k=s1.length();//window size
        int n=s2.length();
        for(int i=0;i<k;i++){
            mp1[s1[i]]++;
        }
        // fixed window of size k should be searched in s2 
        int i=0,j=0;
while(j<n){
mp2[s2[j]]++;
if(j-i+1<k) j++;
else if(j-i+1==k){
    if(mp1==mp2) return true;
    mp2[s2[i]]--;
    if(mp2[s2[i]]==0) mp2.erase(s2[i]);
    i++;
    j++;
}
}

return false;
    }
};