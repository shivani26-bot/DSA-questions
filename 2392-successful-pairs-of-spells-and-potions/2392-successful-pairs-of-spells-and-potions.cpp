class Solution {
public:
int binarySearch(long long num, vector<int>& potions, int m,long long success){

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
        //mlonm
         sort(potions.begin(),potions.end());
         int n=spells.size();
         int m=potions.size();
         vector<int>ans;
         //o(nlogm)
         for(int i=0;i<n;i++){
           long long num= spells[i];
           int count=binarySearch(num, potions,m,success);
            cout<<count;
            ans.push_back(count);
         }
return ans;
    }
};