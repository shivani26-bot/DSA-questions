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