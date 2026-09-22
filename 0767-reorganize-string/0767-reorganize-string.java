class Solution {
    public String reorganizeString(String s) {
        int[] freq = new int[26];
for(char c: s.toCharArray()){
    freq[c-'a']++;
}

int n= s.length();
for(int f: freq){
    if(f>(n+1)/2) return "";
}

List<int[]> sorted = new ArrayList<>();
for(int i=0;i<26;i++){
    if(freq[i]>0){
        //for a list with {freq, char}
        sorted.add(new int[]{freq[i],i});
    }
}

sorted.sort((a,b) -> b[0]-a[0]);

char[] result = new char[n];
int i=0;
for(int[] entry: sorted){
    int count = entry[0];
    char c = (char) (entry[1]+'a');
    while(count>0){
        result[i]= c;
        i+=2;
        count--;
        if(i>=n) i=1;
    }

}
return new String(result);
    }
}