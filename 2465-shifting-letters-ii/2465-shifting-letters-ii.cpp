class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
    //    difference array technique: here we don't need to update the array after applying operation in range
    // hence difference array technique is suitable for this instead of segment tree 
    //  s = "abc", shifts = [[0,1,0],[1,2,1],[0,2,1]]
    //  s=  a   b   c
    //     -1  -1
    //         +1  +1
    //     +1  +1  +1
    //     --------------------
    //     0    1   2=> 0 means a has no impact, b is increased by 1 element, c is increased by 2 element
    // +1=> element is increased by 1, forward shift
    // -1=> element is decreased by 1, backward shift


    // apply difference array
    // a  b  c
    // -1 0  1
    // -1 1  1
    //  0 1  1
    //  0 1  2 => cumulative sum
    int n=s.length();
vector<int>arr(n,0);
for(auto it:shifts){
    int start=it[0];
    int end=it[1];
    int direction= it[2]==0 ?-1: 1;
    arr[start]+=direction;
    if(end+1<n){
    direction= direction==-1?1:-1;
    arr[end+1]+=direction;
}

}

for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;

for(int i=1;i<n;i++){
    arr[i]=arr[i]+arr[i-1];
}

for(int i=0;i<n;i++){
       int shift= arr[i]%26;
       if(shift<0) shift+=26;
       s[i]=((s[i]-'a' +shift)%26)+'a';
}
return s;
    }
};