class Solution {
    public int minDeletions(String s) {
             int[] freq= new int[26];
        for(char c: s.toCharArray()) freq[c-'a']++;

Set<Integer>st= new HashSet<>();
        int deletions=0;
        for(int f: freq){
            if(f==0) continue;
            while(f>0 && st.contains(f)){
                f--;
                deletions++;
            }


            if(f>0) st.add(f);
        }
        return deletions;
    }
}