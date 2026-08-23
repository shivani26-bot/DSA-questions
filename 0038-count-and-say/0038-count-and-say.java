class Solution {
    public String countAndSay(int n) {
              if(n==1) return "1";
        if(n==2) return "11";

        String s= countAndSay(n-1);

        StringBuilder ans= new StringBuilder();
        for(int i=0;i<s.length();i++){
            int count =1;
            while(i+1< s.length() && s.charAt(i)==s.charAt(i+1)){
                count++;
                i++;
            }
            ans.append(count);
            ans.append(s.charAt(i));

        }
        return ans.toString();
    }
}