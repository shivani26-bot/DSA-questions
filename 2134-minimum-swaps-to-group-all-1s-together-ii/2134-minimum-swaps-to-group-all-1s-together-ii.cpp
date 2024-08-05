class Solution {
public:
    int minSwaps(vector<int>& nums) {
        // int totalOnes=0;
        // int n=nums.size();
        // for(auto num: nums){
        //     totalOnes+=num;
        // }
        // if(totalOnes==0) return 0;
        // vector<int>doubleNums=nums;
        // for(int i=0;i<n;i++){
        //     doubleNums.push_back(nums[i]);
        // }
        // int i=0;
        // int j=0;
        // int minmSwaps=INT_MAX;
        // int currOnes=0;
        // while(j<doubleNums.size()){
        //     if(doubleNums[j]==1) currOnes+=doubleNums[j];
        //     if(j-i+1<totalOnes) j++;
        //     else if(j-i+1==totalOnes){
        //       int numberOfSwaps=totalOnes-currOnes;
        //       minmSwaps= min(minmSwaps, numberOfSwaps);
        //       currOnes-=doubleNums[i];
        //       i++;
        //       j++;
        //     }
       
        // }
        // return minmSwaps;
        // without using extra space 
        int totalOnes=0;
        int n=nums.size();
        for(auto num: nums){
            totalOnes+=num;
        }
        if(totalOnes==0) return 0;
    
        int i=0;
        int j=0;
        int minmSwaps=INT_MAX;
        int currOnes=0;
        while(j<2*n){
            if(nums[j%n]==1) currOnes+=nums[j%n];
            if(j-i+1<totalOnes) j++;
            else if(j-i+1==totalOnes){
              int numberOfSwaps=totalOnes-currOnes;
              minmSwaps= min(minmSwaps, numberOfSwaps);
              currOnes-=nums[i%n];
              i++;
             j++;
            }
       
        }
        return minmSwaps;
    }
};

// trick for any problem involving circular subarray {1,1,0,1}
// append the same array , {1,1,0,1,1,1,0,1}