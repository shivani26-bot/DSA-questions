class Solution {
    public int characterReplacement(String s, int k) {
        Map<Character,Integer>mp= new HashMap<>();

        int i=0,j=0;
        int n= s.length();
     
        int maxWindow=0;
        int maxRepeatCharInWindow=0;
        while(j<n){
            char rightChar= s.charAt(j);
            mp.put(rightChar, mp.getOrDefault(rightChar, 0)+1);

            maxRepeatCharInWindow= Math.max(maxRepeatCharInWindow, mp.get(rightChar));
            while(Math.abs(j-i+1)- maxRepeatCharInWindow >k){
                //will require more than k operation
                    char leftChar= s.charAt(i);
                mp.put(leftChar, mp.get(leftChar)-1);
                if(mp.get(leftChar)==0){
                    mp.remove(leftChar);
                    
                }
                i++;
            }

            maxWindow= Math.max(maxWindow, j-i+1);
            j++;
        }
        return maxWindow;

    }
}