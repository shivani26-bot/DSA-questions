class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.length();
        int i=0,j=0;
        int maxWindow=INT_MIN;
        int cost=0;
        while(j<n){
            cost+=abs(s[j]-t[j]);
            if(cost>maxCost){
                while(cost>maxCost){
                    cost-=abs(s[i]-t[i]);
                    i++;
                }
            }
            if(cost<=maxCost){
                maxWindow=max(maxWindow,j-i+1);
               
            }
             j++;
        }
        return maxWindow;
    }
};