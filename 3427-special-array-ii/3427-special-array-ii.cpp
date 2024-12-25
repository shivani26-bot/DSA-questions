class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
    //    int n=queries.size();
    //     vector<bool>ans(n,true);
    //     for(int j=0;j<n;j++){
    //         int u=queries[j][0];
    //         int v=queries[j][1];
    //         for(int i=u;i<v;i++){
    //             if((nums[i]%2==0 && nums[i+1]%2==0) || (nums[i]%2!=0 && nums[i+1]%2!=0)) {
    //                 ans[j]=false;
    //                 break;
    //             }
               
    //         }
          
    //     }
    //     return ans;
    
//    from starti to endi there should be no violating index 
// if we maintain a count of total violating index till current index
   
//    if start=2, end=5
//    we will make sure that from index 3 to 5 there should be 
//    no violating index to make that subarray special 
//  0 1 2 3 4 5 6 7 8 9
// [a,b,c,d,e,f,g,h,i,j]
//  e e o e o e o e o e
//  0 1 1 1 1 1 1 1 1 1 -> violating index count
//  if(cummulativesum[end]-cummulativesum[start]==0) then there is no violating index 
//  and return true;
// nums= [4,3,1,6] queries=[(0,2),(0,3)]
// cumsum=[0,0,1,1]
// cumsum[i]=total violating indices count till index i
// if start=0, end=2
// start index will never be violating, hence always see from index start+1 to end
// hence find cumsum[end]-cumsum[start] to get total voilating index between start and end 
int n=nums.size();
vector<int>badIndex(n,0);//badIndex[i]=total count of violating index till index i
// o(n)
for(int i=1;i<n;i++){
     if(nums[i]%2 == nums[i-1]%2) {//violating index
        badIndex[i]=1+badIndex[i-1];
     }
     else badIndex[i]=badIndex[i-1];
    
}
int m=queries.size();
vector<bool>ans(m,false);
// o(m)
int i=0;
for(auto it: queries){
    int start=it[0];
    int end=it[1];
    if(badIndex[end]-badIndex[start]==0) ans[i]=true;
   i++;
}
return ans;
// total: o(n+m)
    }
};