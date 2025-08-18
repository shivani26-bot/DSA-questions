class Solution {
public:
void solve(int n, int k, string& temp, vector<string>&result,int &count){
    if(temp.length()==n){
        result.push_back(temp);
        count++;
        return;
    }

for(char ch:{'a','b','c'}){
    if(temp.empty() || temp.back()!=ch){
    temp+=ch;
    solve(n,k,temp,result,count);
    if(count==k) return;
    temp.pop_back();}

}

}
    string getHappyString(int n, int k) {
        string temp="";
        vector<string>result;
        int count=0;
        solve(n,k,temp,result,count);
        for(auto s: result){
            cout<<s<<" ";
        }
        cout<<endl;
        return temp;

    }
};