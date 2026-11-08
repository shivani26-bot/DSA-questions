class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int n=cardPoints.length;
        int totalSum=0;
        for(int p:cardPoints){
            totalSum+=p;
        }
        if(k==n) return totalSum;

        // min subarray sum of size n-k
        int windowSize= n-k;
        int currWindowSum=0;
       
        for(int i=0;i<windowSize;i++){
            currWindowSum+=cardPoints[i];
        }
         int minWindowSum=currWindowSum;

        for(int i=windowSize;i<n;i++){
            currWindowSum+= cardPoints[i] - cardPoints[i-windowSize];
            minWindowSum= Math.min(minWindowSum, currWindowSum);
        }
        return totalSum-minWindowSum;
        
    }
}