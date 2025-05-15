class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size();//greed factor of child array
        int m=s.size();//cookie size array
sort(g.begin(),g.end());
sort(s.begin(),s.end());
int i=0,j=0;
int count=0;
while(i<n && j<m){
    if(s[j]>=g[i]){
        count++;
        j++;
            i++;
    }
   else if(g[i]>s[j]) j++;

}
return count;
    }
};

// g:[10,9,8,7]
// s:[5,6,7,8]