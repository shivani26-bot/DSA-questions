class Solution {
    public int[] decrypt(int[] code, int k) {
        
        int n=code.length;
        int i=-1,j=-1;
        int[] ans= new int[n];
        if(k==0) return ans;
        if(k>0){
            i=1;
            j=k;
        }
        if(k<0){
            i=n-Math.abs(k);
            j=n-1;
        }

        int windowSum=0;
        // k is a method parameter. In Java, method parameters share the same scope as local variables declared inside the method body.
        for(int p=i;p<=j;p++){
            windowSum+=code[p];
        }

        for(int p=0;p<n;p++){
            ans[p]=windowSum;
            windowSum-=code[i%n];
            i++;
            windowSum+=code[(j+1)%n];
            j++;

        }
        return ans;
    }
}