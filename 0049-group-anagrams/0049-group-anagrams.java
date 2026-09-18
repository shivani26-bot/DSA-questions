class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
          Map<String, List<String>> mp = new HashMap<>();
        for(String str: strs){
            // sort the string 
            char[] chars = str.toCharArray();
            Arrays.sort(chars);
            String key= new String(chars);

            mp.computeIfAbsent(key, k-> new ArrayList<>()).add(str);
        }

        return new ArrayList<>(mp.values());
    }
}