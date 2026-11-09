class Solution {
    public String minWindow(String s, String t) {
        int n=s.length();
        Map<Character,Integer>mp= new HashMap<>();

        for(char ch: t.toCharArray()){
            mp.merge(ch, 1, Integer::sum);
        }
        int count= mp.size();
        int minLen=Integer.MAX_VALUE;
        int minStart=0;

        int i=0,j=0;
        while(j<n){
            char rightChar=s.charAt(j);
            if(mp.containsKey(rightChar)){
                mp.merge(rightChar,-1, Integer::sum);
                if(mp.get(rightChar)==0){
                    count--;
                }
            }
               j++;
            while(count==0){
                char leftChar= s.charAt(i);
                if(j-i<minLen){
                    minStart=i;
                    minLen=j-i;
                }
                if(mp.containsKey(leftChar)){
                    mp.merge(leftChar, 1, Integer::sum);
                    if(mp.get(leftChar)==1) count++;
                }
                i++;
            }

         
        }
        return  minLen!=Integer.MAX_VALUE? s.substring(minStart,minStart+minLen):"";

    }
}