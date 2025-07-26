class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        unordered_map<int,int>mp;

        int i=0,j=1,n=colors.size();
        int badPairs=0;
        int alternateGroup=0;
        while(i<n){
            if(colors[j%n]==colors[(j-1)%n]) badPairs++;
            if(j-i+1<k) j++;
            else if(j-i+1==k){
               if(badPairs==0) alternateGroup++;
            //   if(colors[i%n]==colors[(i+1)%n]) badPairs--;
                i++;
                 if(colors[i%n]==colors[(i-1)%n]) badPairs--;
                j++;
            }
        }
        return alternateGroup;
    }
};