class Solution {
    public int maxTurbulenceSize(int[] arr) {
        int n=arr.length;
        int maxLen=1;

        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(arr[j]==arr[j-1]) break; //we have to check < & > , if == comes break and check a new subarray
        //         int  currSign= arr[j] > arr[j-1] ? 1 :-1;

        //         // for the first pair 
        //         if(j==i+1){
        //             maxLen= Math.max(maxLen, 2);
        //         }else{
        //             int prevSign= arr[j-1] > arr[j-2] ? 1:-1;

        //             if(currSign==prevSign) break;//adjacent sign must alternate
        //             maxLen= Math.max(maxLen, j-i+1);

        //         }
        //     }
        // }
        // return maxLen;

               int up=1; //increment when, arr[i]>arr[i-1]
        int down=1;// increment when , arr[i]<arr[i-1]

        for(int i=1;i<n;i++){

            if(arr[i]>arr[i-1]){
                up=down+1;
                down=1;
            }else if(arr[i]<arr[i-1]){
                down=up+1;
                up=1;
            }else{
                up=1;
                down=1;
            }

            maxLen=Math.max(maxLen, Math.max(up,down));
        }
        return maxLen;
        
    }
}