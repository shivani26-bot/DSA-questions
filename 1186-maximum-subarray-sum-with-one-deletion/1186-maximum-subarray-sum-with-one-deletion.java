class Solution {
    public int maximumSum(int[] arr) {
        int n=arr.length;

        // max subarray sum ending at index i 
        int[] forward= new int[n];
        forward[0]=arr[0];
        for(int i=1;i<n;i++){
            forward[i]= Math.max(arr[i], forward[i-1]+arr[i]);
        }

        // max subarray sum starting at index i 
        int[] backward = new int[n];
        backward[n-1]= arr[n-1];
        for(int i=n-2;i>=0;i--){
            backward[i]= Math.max(arr[i], backward[i+1]+arr[i]);
        }

        // no deletions :best of forward[i];
        int maxSum= Integer.MIN_VALUE;
        for(int i=0;i<n;i++){
            maxSum= Math.max(maxSum, forward[i]);
        }

        // One deletion: skip element k, combine left and right parts
        for(int i=1;i<n-1;i++){
            maxSum= Math.max(maxSum, forward[i-1]+backward[i+1]);
        }

        return maxSum;
        
    }
}