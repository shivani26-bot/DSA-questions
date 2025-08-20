class Solution {
public:
int n;

bool isUnique(string s){
    set<char> st;
    for(auto i: s) st.insert(i);

    if(st.size()==s.size()) return true;

    return false;
}
int maxLen=INT_MIN;
void solve(vector<string>& arr,int idx,string temp){
        maxLen=max(maxLen,(int) temp.length());
    for(int j=idx;j<n;j++){
        if(!isUnique(temp+arr[j]))continue;
       
       solve(arr,j+1,temp+arr[j]);
   
}
 
}
    int maxLength(vector<string>& arr) {
      n=arr.size();
    
      solve(arr, 0,"");  
      return maxLen;
    }
};