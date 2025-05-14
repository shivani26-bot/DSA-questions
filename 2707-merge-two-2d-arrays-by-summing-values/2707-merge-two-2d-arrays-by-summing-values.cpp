class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>>ans;
        int n= nums1.size(),m=nums2.size();
        int k= min(n,m);
        int i=0,j=0;
        while(i<n && j<m){
            int id1=nums1[i][0];
            int id2=nums2[j][0];
            int val1=nums1[i][1];
            int val2=nums2[j][1];
            if(id1==id2){
                int sum=val1+val2;
                ans.push_back({id1,sum});
                i++;
                j++;
            }
            else if(id1<id2){
                ans.push_back({id1,val1});
                i++;
            }
            else{
                ans.push_back({id2,val2});
                j++;
            }
        }

  while(j<m){
     int id=nums2[j][0];
     int val=nums2[j][1];
       ans.push_back({id,val});
       j++;
  }  


  while(i<n){
     int id=nums1[i][0];
     int val=nums1[i][1];
       ans.push_back({id,val});
       i++;
  
}
        return ans;
    }
};