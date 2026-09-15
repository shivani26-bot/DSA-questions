class Solution {
    public int firstUniqChar(String s) {
        int[] freq = new int[26];

//         for(int i=0;i<s.length();i++){
//             freq[s.charAt(i)-'a']++;
//         }

//  for(int i=0;i<s.length();i++){
//              if(freq[s.charAt(i)-'a']==1) return i;
//         }
        

//         return -1;

Map<Character,Integer> count= new HashMap<>();
Deque<Integer> ele= new ArrayDeque<>();
for(int i=0;i<s.length();i++){
    Character ch= s.charAt(i);
    count.merge(ch, 1, Integer::sum);

    ele.addLast(i);
    while(!ele.isEmpty() &&  count.get(s.charAt(ele.peekFirst())) > 1 ){
        ele.pollFirst();
    }
}

 return ele.isEmpty() ? -1 : ele.peekFirst();
    }
}