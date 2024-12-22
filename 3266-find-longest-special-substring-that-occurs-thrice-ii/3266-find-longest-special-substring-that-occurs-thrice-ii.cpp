class Solution {
public:

    int maximumLength(string s) {
    //  2981. Find Longest Special Substring That Occurs Thrice I
    // prerequisite for this question, this question has higher constraints
    // aaaa
    // aaaa=1
    // aaa=2 //in aaaa->there is also aaa, hence count=2
    // aa=3// in aaa,aaaa there is also aa, hence count =3
    // a=4 //in aaaa,aaa,aa there is also a, hence count =4
    // hence we can store in a table
    // a with 4 times, has frequency of 1
    // a with 3 times, has frequency of 2
    // a with 2 times, has frequency of 3
    // a with 1 times, has frequency of 4
    //    1   2   3   4 -> length of character occured in a substring
    // a  4   3   2   1   -> number of time that substring occured
//     hence we can store the info in table
// how to store info about substring with same character in 2d array
//          a  aa  aaa  aaaa
//      0   1  2    3    4   = column length =length of string s+1
// a-0      4  3    2    1
// b-1
// c-2
// .
// .
// z-25

// also find the cumulative sum from right to left in the column 
// as we get cumulative sum >= 3 then we should break because moving backward
// will only give substring with lesser length
// o(26*n)~o(n)
int n=s.length();
vector<vector<int>>matrix(26,vector<int>(n+1,0));
char prev_char=s[0];
int len=0;
//fill 2d matrix first 
for(int i=0;i<n;i++){
    char curr_char=s[i];
    if(curr_char==prev_char){
        len++;
        matrix[curr_char-'a'][len]++;
    }
    else{
        //new character found, reset length to 1
        len=1;
        matrix[curr_char-'a'][len]++;
        // update the prev_char as well 
        prev_char=curr_char;
    }
}
int result=0;
for(int row=0;row<26;row++){
    int currSum=0;
    for(int col=n;col>=1;col--){
        currSum+=matrix[row][col];
        if(currSum>=3){
            result=max(result,col);
            break;
        }
    }
}
return result==0 ?-1:result;

    }
};