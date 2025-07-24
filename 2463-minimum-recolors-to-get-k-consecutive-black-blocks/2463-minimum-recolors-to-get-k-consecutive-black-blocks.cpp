class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.length();

        int i=0,j=0;
        int minOperation=0;
        int result=INT_MAX;
        while(j<n){
            if(blocks[j]=='W') minOperation++;

            if(j-i+1<k) j++;
            else if(j-i+1==k){
                result=min(result,minOperation);
                if(blocks[i]=='W') minOperation--;
                i++;
                j++;
            }
        }
        return result;
    }
};