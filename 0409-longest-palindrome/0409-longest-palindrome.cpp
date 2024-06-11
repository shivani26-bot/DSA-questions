class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        int n=s.length();
        for(int i=0;i<n;i++){
            // if(mp.find(s[i])!=mp.end())
            mp[s[i]]++;
            // else mp[s[i]]=1;
        }
        int length=0;
    int maxm=0;
     bool isFalse=false;
        for(auto it:mp){
            if(it.second%2==0){
        
              length+=it.second;
            }
            else{
             
             length+= it.second;
             if(!isFalse) isFalse=true;
             else length-=1;
              
            }
        }
    
       
        return length;
    }
};