class Solution {
    public int compress(char[] chars) {
      
        int i=0,count=0;
        int n=chars.length;
        int write=0;
     

        while(i<n){
            count=0;
            char currChar=chars[i];

            
            while(i<n && chars[i] == currChar){
                count++;
                i++;
            }

            chars[write++]= currChar;
            if(count>1){
                for(char c: String.valueOf(count).toCharArray()){
                    chars[write++]=c;
                }
            }

        }
        return write;
    }
}