class Solution {
    public boolean backspaceCompare(String s, String t) {
               int n=s.length();
        int m=t.length();
        int i=n-1,j=m-1;
        int count1=0, count2=0;
        StringBuilder newS= new StringBuilder();
        StringBuilder newT= new StringBuilder();

        while(i>=0){
            if(s.charAt(i)== '#'){
                count1++;
            }
            else{
                if(count1>0){
                    count1--;
                }
                else{
                    //   newS.append(s.charAt(i));
                    newS.insert(0, s.charAt(i));
                }
            }
            i--;
        }

        while(j>=0){
                   if(t.charAt(j) == '#' ){
                count2++;
            }
            else{
              if(count2>0){
                    count2--;
                }
                else{
                    //   newT.append(t.charAt(j));
                    newT.insert(0, t.charAt(j));
                }
            }
            j--;
        }

        return newS.toString().equals(newT.toString());
    }
}