class Solution {
    public int longestSubstring(String s, int k) {
         int n=s.length();
        int maxWindow=0;

        for(int targetUnique=1;targetUnique<=26;targetUnique++){
            int left=0,right=0;
            int[] freq= new int[26];
            int unique=0, countAtLeastK=0;

            while(right<n){

                if(unique<=targetUnique){
                    // expand
                    int rIdx= s.charAt(right)- 'a';
                    if(freq[rIdx]==0) unique++;
                    freq[rIdx]++;
                    if(freq[rIdx]==k) countAtLeastK++;
                    right++;
                }else{
                    int lIdx= s.charAt(left)-'a';
                    if(freq[lIdx]==k) countAtLeastK--;
                    freq[lIdx]--;
                    if(freq[lIdx]==0) unique--;
                    left++;
                }

                if(unique == targetUnique && unique==countAtLeastK){
                    maxWindow= Math.max(maxWindow, right-left);
                }

            }

        }
        return maxWindow;
    }
}