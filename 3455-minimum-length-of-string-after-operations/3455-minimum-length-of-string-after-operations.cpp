class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        if(n<=2) return n;
map<char,int>mp;
for(int i=0;i<n;i++){
    mp[s[i]]++;
}
int sum=0;
for(auto it: mp){
    while(it.second>2){
        it.second-=2;
    }
    sum+=it.second;
}
return sum;
    }
};