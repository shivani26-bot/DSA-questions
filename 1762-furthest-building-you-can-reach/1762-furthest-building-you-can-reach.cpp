class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // int ans=0;
        // if(bricks==0 && ladders==0 && heights[0]<heights[1]) return 0;
        // for(int i=0;i<heights.size()-1;i++){
        //     if(heights[i]>=heights[i+1]){
        //                 ans=i+1;
        //                 continue;
        //     }
        //     else{
        //         if(bricks >= (heights[i+1]-heights[i])){
        //             int brick=(heights[i+1]-heights[i]);
        //         bricks-=brick;
        //         continue;
        //         }
        //         else if(ladders>0)
        //         {
        //             ladders-=1;
        //             continue;
        //         }
        //         else {
        //             ans=i;
        //             break;
        //         }
        //     }
           
        // }
        // cout<<ans;
        // return ans==0? heights.size()-1: ans;
        // for very high height difference use ladder and low height difference use bricks- greedy
        // we go on all the indexes , and on ith index get all the previous jumps ,ie height of all the jumps , sort all the previous jumps
        // grab k maximum jumps from that which can be performed by ladder , and check remaining jumps can be performed by bricks or not
        //    time: o(n*nlogn)
        // hence we know that in sorting when we try to find minimum and maximum k elements then we can improvise using minheap or maxheap
        // o(n*nlogk)
        // we can also use binary search because upto some particular index its possible to reach but after a particular index we can't go
        // rather than going linearly on each index do binary search, and apply greedy on the indexes
        // o(logn * nlogn)
        // if we have 2 ladders we have to make 3 jumps, for the 3rd jump grab the minimum difference and handle it with number of bricks
        // in order to get minimum difference we can use priority queue
        // o(nlogn)
        // if size of pq > ladders grab the minimum diff from the pq and handle with number of remaining bricks you have
        //  priority_queue<int> p;
    
        // int i=0, diff =0; 
        // for(i=0; i<h.size()-1; i++){ 
            
        //     diff = h[i+1]-h[i];
            
        //     if(diff <= 0){
        //         continue;
        //     }

        //     b -= diff; 
        //     p.push(diff); 
       
        //     if(b < 0){
        //         b += p.top(); 
        //         p.pop(); 
        //         l--;
        //     }

          
        //     if(l < 0) break;
        // }
        
        
        // return i;

        priority_queue<int, vector<int>, greater<int>>pq;

        for(int i=0;i<heights.size()-1;i++){
            int diff= heights[i+1]-heights[i];
            if(diff>0) pq.push(diff);
            if(pq.size()>ladders) {
                bricks-=pq.top();
                pq.pop();
            }
            if(bricks<0) return i;
        }
        return heights.size()-1;
 }
};