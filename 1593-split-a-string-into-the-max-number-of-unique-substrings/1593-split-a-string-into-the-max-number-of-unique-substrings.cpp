class Solution {
public:

int solve(int i,  string &s,set<string>st){

// if(i>=s.length()) return 0;
if(i>=s.length()) return st.size();
int maxi=INT_MIN;
for(int index=i;index<s.length();index++){
    string str=s.substr(i,index-i+1);
    if(st.find(str)==st.end()){
        st.insert(str);
        //  maxi= max(maxi,1+solve(index+1,s,st));
    maxi= max(maxi,solve(index+1,s,st));
    st.erase(str);
    
    }
 
}
return maxi;
   
}
    int maxUniqueSplit(string s) {
        int n=s.length();
set<string>st;
return solve(0,s,st);

    }
};