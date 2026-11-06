class Solution {
    public boolean checkInclusion(String s1, String s2) {
    //     Map<Character,Integer> mp= new HashMap<>();
    //     int i=0, j=0;
    //     int k=s1.length();
    //     int n=s2.length();
    //     for(char ch: s1.toCharArray()){
    //         mp.put(ch, mp.getOrDefault(ch,0)+1);
    //     }
    //     int count=mp.size();

    //      while(j<n){
    //         char rightChar= s2.charAt(j);
    //         if(mp.containsKey(rightChar)){
    //             mp.put(rightChar,mp.get(rightChar)-1);
    //             if(mp.get(rightChar) == 0){
    //                 count--;
    //             }

    //         }

    //         if(j-i+1<k) j++;
    //         else if(j-i+1==k){
    //             if(count==0) return true;
    //             char leftChar= s2.charAt(i);

    //             if(mp.containsKey(leftChar)){
    //                 mp.put(leftChar, mp.get(leftChar)+1);
    //                 if(mp.get(leftChar)==1)
    //                 count++;
    //             }
    //             i++;
    //             j++;
    //         }
    //     }
    //    return false;

     int[] pCount= new int[26];
        int[] sCount= new int[26];
       

        for(char ch: s1.toCharArray()){
            pCount[ch-'a']++;
        }

        int i=0,j=0;
        int sLen=s2.length();
        int pLen=s1.length();

        while(j<sLen){
            char rightChar= s2.charAt(j);
            sCount[rightChar-'a']++;
            if(j-i+1<pLen) j++;
            else if(j-i+1==pLen){
                if(Arrays.equals(sCount, pCount)){
                    return true;
                }
                char leftChar= s2.charAt(i);
                sCount[leftChar-'a']--;
                i++;
                j++;
            }
        }
        return false;


    }
}