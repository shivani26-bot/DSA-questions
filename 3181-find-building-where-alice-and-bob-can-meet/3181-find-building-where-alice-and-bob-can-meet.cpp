class Solution {
public:
void buildST(vector<int>& heights,int idx, int l, int r,vector<int>&segmentTree){
    if(l==r){
        segmentTree[idx]=l;//store index instead of element
        return;
    }
    int mid=l+(r-l)/2;
    buildST(heights, 2*idx+1,l,mid,segmentTree);
    buildST(heights,2*idx+2,mid+1,r,segmentTree);
// int leftMaxIdx=segmentTree[2*idx+1];
// int rightMaxIdx=segmentTree[2*idx+2];
// if(heights[leftMaxIdx]>=heights[rightMaxIdx]){
// segmentTree[idx]=leftMaxIdx;
// }
// else{
// segmentTree[idx]=rightMaxIdx;
// } 

    segmentTree[idx] = (heights[segmentTree[2 * idx + 1]] >= heights[segmentTree[2 * idx+ 2]]) ?
                        segmentTree[2 * idx + 1] : segmentTree[2 * idx + 2];
}
int querySegmentTree(int start, int end , int idx, int l, int r,  vector<int>&segmentTree,vector<int>& heights)
{
  //outof bound
     if(l>end || r<start) return -1;// invalid index
    //  within the range
    if(l>=start && r<=end) return segmentTree[idx];//returns index of max element
    
    int mid= l+(r-l)/2;
int leftMaxIdx=querySegmentTree(start, end,2*idx+1,l,mid,segmentTree,heights);
int rightMaxIdx=querySegmentTree(start,end,2*idx+2,mid+1,r,segmentTree,heights);
if(leftMaxIdx==-1) return rightMaxIdx;
if(rightMaxIdx==-1) return leftMaxIdx;
return (heights[leftMaxIdx]>=heights[rightMaxIdx])?leftMaxIdx:rightMaxIdx;

}
//RMIQ - range maximum index query
 int RMIQ(int start, int end, int n,  vector<int>&segmentTree,vector<int>& heights){
    
    return querySegmentTree(start,end,0,0,n-1,segmentTree,heights);
   
 }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
//          heights = [6,4,8,5,2,7], queries = [[0,1],[0,3],[2,4],[3,4],[2,2]]
//          for [0,1] alice and bob are on different buildings
//         height[0]>height[1] alice can't move from 0 to 1 hence both has to find the other building where they can meet
//          in right range from (2,5) find the building which is greater than heights[0] and heights[1] and as left as possible
//          ans will be index 2
//          as heights[2] is greater than both heights[0] and heights[1] and as left as possible in the right range

// first check whether both are present on same building or not
// if yes then return the index,because they are at same index means they met each other already
// if not then check whether we can go from a to b or not
// if yes then ans will be index b where both will meet
// if not then find the range maximum index query and binary search in right range
   int n=heights.size();
   vector<int>segmentTree(4*n);
   vector<int>ans;

   buildST(heights,0,0,n-1,segmentTree);
    for(int i=0;i<queries.size();i++){
  
        int min_idx=min(queries[i][0],queries[i][1]);
         int max_idx=max(queries[i][0],queries[i][1]);
        if(min_idx==max_idx || heights[min_idx]<heights[max_idx] ){
             ans.push_back(max_idx); 
             continue;
             }
      
//search in right range
            int l=max_idx+1;
            int r=n-1;
//perform binary search on index
   int result_idx=INT_MAX;//we have to find minimum result index here
while(l<=r){
int mid=l+(r-l)/2;
//we will apply rmiq from l to mid, if we get the idx then we try to move more left by doing r=mid-1
// but if we get idx=-1 then we will apply rmiq in right side from mid+1 to n-1
int idx=RMIQ(l,mid, n,segmentTree,heights);
if(heights[idx]>max(heights[min_idx],heights[max_idx])){
result_idx=min(result_idx,idx);//possible ans
r=mid-1;//try to find better answer in left most range
}
else{
//go to right side
l=mid+1;
}
}
if(result_idx==INT_MAX)
ans.push_back(-1);
else  
ans.push_back(result_idx);
        

    }
    return ans;
    
    
    }
};