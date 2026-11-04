class Solution {
    public int minimumRecolors(String blocks, int k) {


        int i=0, j=0, n=blocks.length();
        int countWhiteBalls=0;
        int minOperation =Integer.MAX_VALUE;
        while(j<n){
            if(blocks.charAt(j) == 'W') countWhiteBalls++;
            if(j-i+1<k) j++;
            else if(j-i+1==k){
               
                minOperation= Math.min(minOperation, countWhiteBalls);
                if(blocks.charAt(i)=='W'){
                    countWhiteBalls--;
                }
                i++;
                j++;
            }
        }
        return minOperation;
        
    }
}