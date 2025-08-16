class Solution {
public:
int n;
vector<string>result;
bool isValid(string str){
    int num= stoi(str);
    if(num>=0 && num<=255) return true;
    return false;
}
void solve(string s, int idx,int countDots, string temp){

if(idx==n && countDots==4){
    temp.pop_back();
    result.push_back(temp);
    return;
}
if(countDots>4) return;
    for(int j=idx;j<min(idx+3,n);j++){
        string subs=s.substr(idx,j-idx+1);
        // If the substring has a length greater than 1, the first character should not be '0' (to avoid leading zeros).
        if(isValid(subs) && (idx==j || s[idx]!='0')){
            solve(s,j+1,countDots+1,temp+subs+".");
        }
    }
}
    vector<string> restoreIpAddresses(string s) {
        n=s.length();
       if(n>12) return result;//result is not possible as 4 integers and each range from 0 to 255 , in worst case 4*3=12 to form a valid answer
       
        solve(s,0,0,"");
        return result;
    }
};


// class Solution {
// //     bool good(string s){
// //     string str;
// //     for(char c: s){
// //         if(c=='.'){
// //     if(!str.size() || str.size()>3 || stoi(str)>255 || str[0]=='0' && str.size()>1) return false;
// //             str="";
// //         }
// //         else
// //         str+=c;
// //     }
// //     if(!str.size() ||str.size()>3 || stoi(str)>255|| str[0]=='0' && str.size()>1) return false;
// //     return true;
// // }
// void dfs(int i, int cntdots, string &s,string t, vector<string>&ans){
//    if(i==s.size() && cntdots==4){
//        t.pop_back();
//        ans.push_back(t);
//        return;
//    }
//     if(cntdots>4) return;
//     for(int j=i; j<min(i+3,(int)s.size());j++){
//         if(stoi(s.substr(i,j-i+1))<= 255&& (i==j || s[i]!='0')){
//             dfs(j+1,cntdots+1,s,t+s.substr(i,j-i+1)+".",ans);
//         }
//     }
// }
// public:

//     vector<string> restoreIpAddresses(string s) {
//     //     int n=s.length();
//     //     vector<string>ans;
//     // for(int i=0;i<n;i++){
//     //     for(int j=i+1;j<n;j++){
//     //         for(int k=j+1;k<n;k++){
//     //             string ip=s.substr(0,i+1)+ "."+s.substr(i+1,j-i)+"."+s.substr(j+1,k-j)+"."+s.substr(k+1);
//     //             if(good(ip)) ans.push_back(ip);
//     //         }
//     //     }
//     // }   
//     // return ans; 

// // The given code is a solution to the problem of restoring valid IP addresses from a given string s. The goal is to insert dots into the string in such a way that it forms valid IP addresses.

// // The solution uses a depth-first search (DFS) approach to explore all possible combinations of inserting dots. The dfs function is a recursive function that takes several parameters:

// // i represents the current index in the string s.
// // cnt represents the count of dots inserted so far.
// // s is the original input string.
// // t is a temporary string that keeps track of the current combination of IP address parts being formed.
// // ans is the vector of strings that will store the valid IP addresses.
// // The base cases of the recursion are as follows:

// // If i reaches the end of the string s and the count cnt is equal to 4 (indicating that 4 parts of the IP address have been formed), it means a valid IP address has been formed. In this case, the temporary string t is appended to ans after removing the last dot (using t.pop_back()).
// // If the count cnt exceeds 4, it means too many dots have been inserted, and the current combination is invalid. In this case, the function returns without further exploration.
// // The recursive part of the function iterates from the current index i up to the minimum of i + 3 and the size of string s. This limits the length of the IP address parts to at most 3 characters. Within the loop, it checks if the substring from i to j (inclusive) is a valid IP address part. This is done by checking two conditions:

// // The substring converted to an integer (stoi) should be less than or equal to 255.
// // If the substring has a length greater than 1, the first character should not be '0' (to avoid leading zeros).
// // If both conditions are satisfied, the dfs function is recursively called with the updated parameters: j + 1 as the new index, cnt + 1 as the increased count, and t + s.substr(i, j - i + 1) + "." as the updated temporary string.
// vector<string>ans;
// if(s.size()>12) return ans;
// dfs(0,0,s,"",ans);
// return ans;

//     }
// };