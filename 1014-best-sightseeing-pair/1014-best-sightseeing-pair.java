class Solution {
    public int maxScoreSightseeingPair(int[] values) {
        int n=values.length;
        // int result=Integer.MIN_VALUE;
        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         result= Math.max(result, values[i]+values[j]+i-j);
        //     }
        // }
        // return result;

             int maxLeftScore= values[0]+0;//always consists of element and index of that element
        int maxScore=0;

        for(int j=1;j<n;j++){
            //at each step we can update our maxScore or maxLeftScore
            maxScore= Math.max(maxScore, maxLeftScore+values[j]-j);
            maxLeftScore= Math.max(maxLeftScore, values[j]+j);//update the best left score for future j's
        }

        return maxScore;

    }
}