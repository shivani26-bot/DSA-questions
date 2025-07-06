class Solution {
public:
// heights=[3,19]
// bricks:87
// ladders=1

// heights=[1,5,1,2,3,4,10000]
// bricks=4
// ladders=1
// from 1 to 5 if we use all bricks then bricks=0, ladders=1
// 5 to 1 nothing is required
// 1 to 2 ladder is required then bricks=0, ladders=0
// farthest we can go upto index=3

// from 1 to 5 if we use ladder, bricks=5, ladders=0
// 5 to 1 nothing is required
// 1 to 2, we use bricks=5-1=4
// 2 to 3 , we use bricks=4-1=3
// 3 to 4 , we use bricks=3-1=2
// farthest we can go upto index=5

// we can't use direct approach like use bricks or ladder whenever you want 
// int n;
// int solve(int i,int j, vector<int>& heights, int bricks, int ladders){
// if(j>=n) return i;//we reached end, and covered all the buildings
// if(bricks<heights[j]-heights[i] && ladders==0) return i; //we can't move further
// if(heights[i]>=heights[j]) return solve(i+1,j+1,heights,bricks,ladders);//go to next building without using ladder or brick

// int brick=0,ladder=0;
// if(bricks>=heights[j]-heights[i]){
//     int requiredBricks=heights[j]-heights[i];
// brick= solve(i+1, j+1, heights, bricks-requiredBricks, ladders);
// }
// if(ladders>0){
//  ladder=solve(i+1,j+1, heights,bricks, ladders-1);
// }
// return max(brick, ladder);
// }
//     int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
// //we have 2 options in the question either use ladder or bricks
// // first we should think of recursion
// // if arr[i]<arr[i+!]
// // we have two options:
// // use bricks, only if height difference arr[i+1]-arr[i]<=bricks
// // use ladder, only if ladder>0
// //                      i  i+1
// //                     {2, 3,  19, 3}:bricks=3, ladder=1
// //           bricks:3-2<=3        ladder:1
// //             i  i+1                 i  i+1
// //         {2, 3, 19, 3}          {2, 3, 19,  3}
// //  can't use     ladder:0          idx:1
// //  bricks             i  i+1 
// //                {2,3,19,3}
// //                        i
// //                {2,3,19,3}  idx:3

// n=heights.size();
// if((bricks==0 && ladders==0 && heights[1]>heights[0]) || n==1) return 0;
// return solve(0,1,heights,bricks,ladders);

//     }

// int n;
// tle
// int solve(int i, vector<int>& heights, int bricks, int ladders){
// if(i+1>=n) return i;//we reached end, and covered all the buildings
// if(bricks<heights[i+1]-heights[i] && ladders==0) return i; //we can't move further
// if(heights[i]>=heights[i+1]) return solve(i+1,heights,bricks,ladders);//go to next building without using ladder or brick

// int brick=0,ladder=0;
// if(bricks>=heights[i+1]-heights[i]){
//     int requiredBricks=heights[i+1]-heights[i];
// brick= solve(i+1, heights, bricks-requiredBricks, ladders);
// }
// if(ladders>0){
//  ladder=solve(i+1, heights,bricks, ladders-1);
// }
// return max(brick, ladder);
// }
//     int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
// n=heights.size();
// if((bricks==0 && ladders==0 && heights[1]>heights[0]) || n==1) return 0;
// return solve(0,heights,bricks,ladders);

//     }

//memoization
//gives mle
// also only two states are changing bricks and ladders, idx for every call is idx+1
// hence we can also use 2d dp instead of 3d to solve this
// int n;

// int solve(int i, vector<int>& heights, int bricks, int ladders,vector<vector<vector<int>>>&dp){
// if(i+1>=n)  return dp[i][bricks][ladders]= i;//we reached end, and covered all the buildings
// if(bricks<heights[i+1]-heights[i] && ladders==0) return dp[i][bricks][ladders]= i; //we can't move further
// if(heights[i]>=heights[i+1]) dp[i][bricks][ladders]= solve(i+1,heights,bricks,ladders,dp);//go to next building without using ladder or brick
// if(dp[i][bricks][ladders]!=-1) return dp[i][bricks][ladders];
// int brick=0,ladder=0;
// if(bricks>=heights[i+1]-heights[i]){
//     int requiredBricks=heights[i+1]-heights[i];
// brick= solve(i+1, heights, bricks-requiredBricks, ladders,dp);
// }
// if(ladders>0){
//  ladder=solve(i+1, heights,bricks, ladders-1,dp);
// }
// return dp[i][bricks][ladders]=max(brick, ladder);
// }
//     int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
// n=heights.size();
// if((bricks==0 && ladders==0 && heights[1]>heights[0]) || n==1) return 0;

// vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(bricks+1,vector<int>(ladders+1,-1)));
// return solve(0,heights,bricks,ladders,dp);

//     }


//recursion

// int n;

// int solve(int i, vector<int>& heights, int bricks, int ladders){
// if(i+1>=n)  return 0;

// if(heights[i]>=heights[i+1]) return 1+solve(i+1,heights,bricks,ladders);//we jumped 1 building

// int brick=0,ladder=0;
// if(bricks>=heights[i+1]-heights[i]){
//     int requiredBricks=heights[i+1]-heights[i];
// brick= 1+solve(i+1, heights, bricks-requiredBricks, ladders);//we jumped 1 building
// }
// if(ladders>0){
//  ladder=1+solve(i+1, heights,bricks, ladders-1);//we jumped 1 building
// }
// return max(brick, ladder);
// }
//     int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
// n=heights.size();
// if((bricks==0 && ladders==0 && heights[1]>heights[0]) || n==1) return 0;

// return solve(0,heights,bricks,ladders);

//     }

// memoization
// int n;
// vector<vector<int>>dp;
// int solve(int i, vector<int>& heights, int bricks, int ladders){
// if(i+1>=n)  return 0;


// if(dp[bricks][ladders]!=-1) return dp[bricks][ladders];

// if(heights[i]>=heights[i+1]) return dp[bricks][ladders]= 1+solve(i+1,heights,bricks,ladders);//we jumped 1 building
// else{//either we can take bricks or ladders
// int brick=0,ladder=0;
// if(bricks>=heights[i+1]-heights[i]){
//     int requiredBricks=heights[i+1]-heights[i];
// brick= 1+solve(i+1, heights, bricks-requiredBricks, ladders);//we jumped 1 building
// }
// if(ladders>0){
//  ladder=1+solve(i+1, heights,bricks, ladders-1);//we jumped 1 building
// }
// return dp[bricks][ladders]=max(brick, ladder);
// }
// return -1;
// }
//     int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
// n=heights.size();
// if((bricks==0 && ladders==0 && heights[1]>heights[0]) || n==1) return 0;
// dp=vector<vector<int>>(bricks+1,vector<int>(ladders+1,-1));
// return solve(0,heights,bricks,ladders);

//     }


//lazy greedy
// we can use a datastructure to maintain bricks used in past
// if we are at a index where we have exhausted all our bricks and ladder
// we think that in past where i used more bricks, instead of bricks i should  have used ladder in that place

// hence max heap
// if heights[i]<heights[i+1] use bricks if you have and store that in heap
// if bricks are exhausted and  heights[i]<heights[i+1] before using ladder
// first check that diff=heights[i+1]-heights[i] < bricks present at top of heap (which is bricks used in past)
// update the brick= pq.top()
// ladder--// because we used it in past, we exchanged the bricks used in past with ladder
// [1,5,1,2,3,4,10000] bricks=4, ladder=1
// pq stores how many bricks used at current level
// from 1 to 5 use bricks, bricks=0, ladder=1, push the bricks used in priority queue :4
// from 5 to 1 nothing is required
// from 1 to 2 we don't have bricks check pq, bricks=4, ladder=0
// pq: empty
// use 1 brick to travel from 1 to 2, bricks=3 store in pq: 1 
// from 2 to 3: bricks=2  pq: 1 1
// from 3 to 4: bricks=1 pq: 1 1 1
// when we are at 4, from 4 to 5 we require, 9996 bricks
// check pq, top element < 9996 (required bricks) hence we have used bricks
// optimally in past and we can't move further
// pq stores max bricks used in past:lazy greedy


    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
int n=heights.size();
priority_queue<int>pq;
int i;
for( i=0;i<n-1;i++){

    // if(ladders==0 && bricks==0 && heights[i+1]>heights[i]) return i;
    if(heights[i]>=heights[i+1]) continue;

        
         int requiredBricks=heights[i+1]-heights[i];
        if(bricks>=requiredBricks){
       
        bricks-=requiredBricks;
        pq.push(requiredBricks);
        }
        else if(ladders>0){
            if(!pq.empty()){
  int maxBrick= pq.top();//max brick used in past
            if(maxBrick>requiredBricks){
            
                bricks+=maxBrick;
                  pq.pop();
                pq.push(requiredBricks);//stores the number of bricks used at current level
                bricks-=requiredBricks;
            
                    // ladders--;// we have to use ladder in past
            }
             
            // else{
            //     ladders--;
            // }

             }
              ladders--; //write once instead of writing thrice, both are correct
            //   this will handle case when maxBrick>requiredBricks,  maxBrick <=requiredBricks, when pq is empty and ladder>0
            
            //  else{//if priority queue is empty which means no bricks then use ladder only
            //     ladders--;
            //  }   
        }
        else break; //when all bricks and ladders is exhausted
    
}
return i;
    }

};