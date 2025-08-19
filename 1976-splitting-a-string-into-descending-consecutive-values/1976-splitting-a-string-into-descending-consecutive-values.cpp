class Solution {
public:
int n;

const long long MAX=999999999999; //12 9's
bool solve(string s, int idx,long long prev,int count,vector<string>&temp){
    if (idx == n) {
        // print one valid sequence when string is completely split
        cout << "Sequence: ";
        for (auto &ele : temp) cout << ele << " ";
        return count>1;//there must be more that 1 elements to form decreasing order
    }
long long num=0;
    for(int j=idx;j<n;j++){
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