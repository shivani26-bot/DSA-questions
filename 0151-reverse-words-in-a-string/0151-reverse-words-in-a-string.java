class Solution {
    public String reverseWords(String s) {
        s=s.trim();
        StringBuilder ans=new StringBuilder();

        int n= s.length();

        for(int i=n-1;i>=0;){

            while(i>=0 && s.charAt(i) == ' '){
                i--;
            }
            int j=i;
            while(i>=0 && s.charAt(i)!=' '){
                i--;
            }

            if(ans.length()>0) ans.append(" ");
          ans.append(s.substring(i+1,j+1));


        }
        return ans.toString();
    }
}