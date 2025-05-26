class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=neededTime.size();
        //i will be pointing to previous max element and j will be pointing to next element
        int minTime=0;
       int i=0, j=1;
       while( j<n){
        if(colors[i]==colors[j]){
            if(neededTime[i]<=neededTime[j]){
                minTime+=neededTime[i];
                i=j;
                j++;
            }
            else if(neededTime[i]>neededTime[j]){
                minTime+=neededTime[j];
                j++;
            }
        }
        else{
            i=j;
            j++;
        }
       }
       return minTime;
    }
};

// "aaabbbabbbb"
// [3,5,10,7,5,3,5,5,4,8,1]
// output:  26