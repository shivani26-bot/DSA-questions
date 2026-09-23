class Solution {
    public int numMatchingSubseq(String s, String[] words) {
        //     int count=0;
        // for(String word: words){
        //     int i=0;
        //     for(char c: s.toCharArray()){
        //         if(i<word.length() && c==word.charAt(i)) i++;
        //     }
        //     if(i==word.length()) count++;
        // }
        // return count;

            List<int[]>[] buckets = new List[26];
        for(int i=0;i<26;i++){
            buckets[i]= new ArrayList<>();
        }

        for(int i=0;i<words.length;i++){
            buckets[words[i].charAt(0)-'a'].add(new int[]{i,0});
        }

        int count=0;
        for(char c: s.toCharArray()){
            List<int[]> current = buckets[c-'a'];
            buckets[c-'a'] =  new ArrayList<>();
            for(int[] entry: current){
                int wordIdx= entry[0];
                int charIdx= entry[1]+1;
                if(charIdx == words[wordIdx].length()) count++;
                else {
                    buckets[words[wordIdx].charAt(charIdx) - 'a'].add(new int[]{wordIdx, charIdx});
                }
            }

        }
        return count;
    }
}