class Solution {
public:
int n;
// That’s about 1e12 (a trillion).
// It’s much smaller than the maximum a long long can hold (1e18).
// So it’s a safe cutoff that avoids overflow — but it’s stricter than necessary.
const long long MAX=1e12; //12 9's can , write upto 1e17
bool solve(string s, int idx,long long prev,int count,vector<string>&temp){
    if (idx == n) {
        // print one valid sequence when string is completely split
        cout << "Sequence: ";
        for (auto &ele : temp) cout << ele << " ";
        return count>1;//there must be more that 1 elements to form decreasing order,problem requires at least 2 numbers (not just one) in the split.
    }
long long num=0;
    for(int j=idx;j<n;j++){
//         you’re turning digits into a number. But:
// s can have length up to 20.
// That means substrings can represent numbers as large as 10^20 - 1.
// A long long in C++ can only safely hold values up to about 9.22 * 10^18 (~18 digits).
// Anything beyond that overflows.
// \U0001f449 So, you need to cap num before it grows too large. That’s why MAX is introduced.
        num=num*10+s[j]-'0';
        if(num>MAX) break;
         //must be strictly decreasing
        if(prev!=-1 && num>=prev) break;
        string subs= s.substr(idx,j-idx+1);
        if(prev==-1 || prev-num==1){
            temp.push_back(subs);
if(solve(s,j+1,num,count+1,temp)) return true;
temp.pop_back();
        }
       
    }
   return false;
}
    bool splitString(string s) {
        n=s.length();
        if(n<=1) return false;
        vector<string>temp;
  return solve(s,0,-1,0,temp);
 
    
    }
};