class Solution {
public:
#define P pair<char,int>
    int maximumLength(string s) {
        // bruteforce 
        // find all the substrings
        // find special substrings among them
        // out of all the special substrings find the longest one

        // optimize: find only special substrings:substring in which only same letters are present
        // aaaa=>
        // possible substrings are, in this case these all are special
        // a,aa,aaa,aaaa
        // a,aa,aaa
        // a,aa
        // a
        // aa has occured atleast three times, and it's length is 2
        // we can maintain count in map 
        // total time=o(n^3)
//         unordered_map<string,int>mp;
//         int n=s.length();
//         for(int i=0;i<n;i++){//o(n)
//             string new_s;
//             for(int j=i;j<n;j++){ //o(n)
//                 if(new_s.empty() || new_s.back()==s[j]){
//                  new_s.push_back(s[j]);
// mp[new_s]++; //new_s string is copied to the map, (new_s ka length() ~ o(n))
//                 }
//                 else {   
//                     break;
//                 } 
//             }    
//         }
//         int result=0;
// for(auto it: mp){
//     string str=it.first;
//     int count=it.second;

//     if(count>=3 && str.length()>result )
//     result=str.length();
// }
// return result==0?-1: result;

// space optimization 
// instead of storing the whole substring everytime like
// a-2
// aa-2
// aaa-1
// aaaa-1
// zzzz-2
// // we can do it like, we can store the character and number of times it occured in the substring and map to number of time the same substring occured in the string 
// {z,4}-2
// {a,4}-1
// {a,1}-2
 map<P,int>mp;
        int n=s.length();
        for(int i=0;i<n;i++){//o(n)
            char ch=s[i];
            for(int j=i;j<n;j++){ //o(n)
                if(ch==s[j]){
                
mp[{ch,j-i+1}]++; 
                }
                else {   
                    break;
                } 
            }    
        }
        int result=0;
for(auto it: mp){
    char ch=it.first.first;
    int count=it.second;
    int len=it.first.second;

    if(count>=3 && len>result )
    result=len;
}
return result==0?-1: result;

    }
};