class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        if(arr.size()==0) return {};
        vector<int>temp(arr.begin(),arr.end()); // O(n)
        sort(temp.begin(),temp.end());//O(n log n)
       unordered_map<int,int>mp;
         int rank=1;
       
        mp[temp[0]]=rank;
        cout<<mp[temp[0]]<<" ";
        for(int i=1;i<n;i++){//O(n)
          
            if(temp[i]!=temp[i-1]){
                rank=rank+1;
            mp[temp[i]]=rank; // O(1)
            cout<<mp[temp[i]]<<" ";
            }
          
        }
        vector<int>result(n);
   for(int i=0;i<n;i++){ //O(n) 
    result[i]=mp[arr[i]]; //performs lookups in the unordered_map, which has O(1)
   }
   return result;
    }
};