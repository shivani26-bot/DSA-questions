class Solution {
public:
//similar to 698. Partition to K Equal Sum Subsets
int n;
bool solve(vector<int>& matchsticks, vector<int>&visited,int target, int idx, int curr_sum, int k){
  if(k==1) return true;
  if(idx>=n) return false;
       if(curr_sum==target) return solve(matchsticks,visited,target,0,0,k-1) ;

    for(int j=idx;j<n;j++){
if(visited[j] || curr_sum+matchsticks[j]>target) continue;
        visited[j]=true;
        if(solve(matchsticks, visited, target, j+1,curr_sum+matchsticks[j],k)) return true;
        visited[j]=false;
    }
    return false;
}
    bool makesquare(vector<int>& matchsticks) {
    //   ( totalsum of array )/4= length of each side of square 
    // hence target for each side is (totalsum of array)/4
    n=matchsticks.size();
    int totalSum=0;
    for(int i=0;i<matchsticks.size();i++){
        totalSum+=matchsticks[i];
    }
    if(n<4 ||  totalSum%4) return false;
    int target= totalSum/4;
    vector<int>visited(n,false);
     sort( matchsticks.begin(), matchsticks.end(),greater<int>());
return solve(matchsticks,visited,target,0,0,4);
    }
};