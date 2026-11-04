class Solution {
    public int numOfSubarrays(int[] arr, int k, int threshold) {
               int i=0,j=0, n=arr.length;

        int sum=0;
        int count=0;

        while(j<n){
            sum+=arr[j];
            if(j-i+1<k) j++;
            else if(j-i+1 == k){
                int average= sum/k;
                if(average>=threshold){
                    count++;
             
                }
                sum-=arr[i];
                i++;
                j++;
            }
        }
        return count;
    }
}