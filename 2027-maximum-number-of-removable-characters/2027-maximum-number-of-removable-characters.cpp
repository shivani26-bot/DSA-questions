class Solution {
public:
int n;
bool isPossible(string s, string p, vector<int>& removable,int mid){

    for(int i=0;i<mid;i++){
       s[removable[i]]='$';
    }
    // cout<<mid<<endl;
 
    //     cout<<s<<endl;
//   cout<<p<<endl;
    int j=0,k=0;
    while(j<s.length() && k<p.length()){
        if(s[j]!='$' && s[j]==p[k]){
         
            k++;
        }
        j++;
    }
 
return k==p.length();
}
    int maximumRemovals(string s, string p, vector<int>& removable) {
      n=removable.size();
        int low=1,high=n;

        int maxK=0;        
while(low<=high){
    int mid=low+(high-low)/2;
    if(isPossible(s,p,removable, mid)){
      
       maxK=mid;
        low=mid+1;
    }
    else high=mid-1;

    //   cout<<s<<endl;
}
return maxK;
    }
};