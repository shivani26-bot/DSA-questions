class Solution {
public:
// o(n+m)
// m=trust relation size 
// n=number of nodes
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>in(n+1);
         vector<int>out(n+1);
         for(auto it:trust){
            out[it[0]]++;
            in[it[1]]++;
         }
         for(int i=1;i<=n;i++){
            if(in[i]==n-1 && out[i]==0) return i;
         }
         return -1;
    }
};