class Solution {
public:
// time and space :o(n)
    int minFlips(string s) {
//          Remove the character at the start of the string s and append it to the end of the string.: similar to string rotation
//          copy a string and append to original string
//          "1100"=> "1100"+"1100"="11001100", find substring of length original string s ie 4
//          total n different rotations
//      all possible rotation of 1100=>    "1100","1001","0011","0110","1100"
// we can find all this in appended string "11001100" if we run a window of size original string , ie 4

//          we append the string because it lets you simulate all possible rotations with a single sliding window. Every window of length n in the doubled string represents a possible rotation of the original

// s1 and s2 is the desired string 
// generate 2 strings s1 and s2 start from 1010 and 0101
// s="11001100"
// compare each index in appended string s with index in s1 and s2, to find out number of flips 

int n=s.size();//original string size
s+=s;//appended string
string s1,s2;
//make desired string of appended string size: starting from 1 and 0 in alternate manner ie 101010101.., 01010101
for(int i=0;i<s.size();i++){
s1+=i%2?'0':'1';//odd index-> 0 and even index-> 1
s2+=i%2?'1':'0';//even index->0, odd index->1
}
int ans1=0,ans2=0,ans=INT_MAX;
for(int i=0;i<s.size();i++){
    if(s1[i]!=s[i]) ans1++;//count the flip
    if(s2[i]!=s[i]) ans2++;
    //slide the window
    //remove the left most element,as it is outside of sliding window, subtract if the left most index was contributing to ans1 or ans2
    if(i>=n){
        if(s1[i-n]!=s[i-n]) ans1--;
        if(s2[i-n]!=s[i-n]) ans2--;
    }
    //find the answer for each window
    if(i>=n-1){
        ans=min({ans,ans1,ans2});
    }


}
return ans;
    }
};