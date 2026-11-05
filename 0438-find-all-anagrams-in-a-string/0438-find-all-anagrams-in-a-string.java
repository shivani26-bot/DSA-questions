class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        Map<Character,Integer>mp = new HashMap<>();
        int i=0,j=0, n=s.length();
        List<Integer> ans= new ArrayList<>();
        int k= p.length();
       
        for(char ch: p.toCharArray()){
            mp.put(ch, mp.getOrDefault(ch,0)+1);
        }
         int count=mp.size();

        while(j<n){
            char rightChar= s.charAt(j);
            if(mp.containsKey(rightChar)){
                mp.put(rightChar,mp.get(rightChar)-1);
                if(mp.get(rightChar) == 0){
                    count--;
                }

            }

            if(j-i+1<k) j++;
            else if(j-i+1==k){
                if(count==0) ans.add(i);
                char leftChar= s.charAt(i);

                if(mp.containsKey(leftChar)){
                    mp.put(leftChar, mp.get(leftChar)+1);
                    if(mp.get(leftChar)==1)
                    count++;
                }
                i++;
                j++;
            }
        }
        return ans;

    }
}