class Solution {
public:
int binarySearch(long long num, vector<int>& potions, int m,long long success){
// cout<<m<<endl;
// for(int i=0;i<m;i++){
//     cout<< potions[i]<<" ";
// }
// cout<<endl;
         int l=0, h=m-1;
         while(l<=h){
            int mid=l+(h-l)/2;
            if(num*potions[mid]<success){
                l=mid+1;
            }
            else h=mid-1;
         }
         return m-l;
}
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
         sort(potions.begin(),potions.end());
         int n=spells.size();
         int m=potions.size();
         vector<int>ans;
         for(int i=0;i<n;i++){
           long long num= spells[i];
           int count=binarySearch(num, potions,m,success);
            cout<<count;
            ans.push_back(count);
         }
return ans;
    }
};