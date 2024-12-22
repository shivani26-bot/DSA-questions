class Solution {
public:
        #define P pair<int, int>
    long long continuousSubarrays(vector<int>& nums) {
    //   how to count subarrays
    // {2,1,2}
    // {2}-> only 1 subarray ie {2}  -length:1
    // {2,1}-> 3 subarrays are: {2}{2,1}{1}  -length:2
    // {2,1,2}-> 6 subarrays are: {2}{2,1}{2,1,2}{1}{1,2}{2}  -length:3
// if at every step we add the length of the array then it will give 
// total number of subarrays at that step
// how to check if a subarray is continous 
// {2,1,2,4} -> 1,4 will not follow the rule, difference between them is not <=2
// hence this subarray is not valid 
// hence we can shrink window 
// in any subarray , if difference between largest and smallest element <=2 then any pair difference will be <=2
// for every subarray we must know the largest and smallest element 
// {2,1,2,4} we shrink the window such that {2,4} remove 2,1
// in order to find max or min in current window efficiently we can use ordered set 
// which will keep elements in sorted order 
// but if we have duplicate elements then that will be not stored again in set
// hence we can use ordered_map

// in ordered map or set, mp.begin() given the first element, mp.rbegin() gives the last element 

// in ordered map, any operation like insertion, deletion, retrieving takes log(n) time 
// in worst case we used to store the elements of valid window  and difference between any element in valid window can be 0,1,2 if difference is > than either of the values then we shrink the window
// hence size of map will be maximum 3 at a time 

// int n=nums.size();
// map<int,int>mp;
// int i=0;
// int j=0;
// long long count=0;
// // total time = o(n*log(3))= o(n)
// // space= o(3)=o(1)
// while(j<n){ //o(n)
//     mp[nums[j]]++;
//     while(abs(mp.rbegin()->first - mp.begin()->first)>2){ //o(log(3)) 3 is the size of map in worst case

//         //it means it's out of bound
//         mp[nums[i]]--;
//         if(mp[nums[i]]==0){
//             mp.erase(nums[i]);
//         }
//         i++;
//     }
//     count+=j-i+1;
//     j++;
// }
// return count;

// we can also use max heap and min heap to store max and min elements in current window 
int i=0;
int j=0;
int n=nums.size();
long long count=0;
// {el,index}
priority_queue<P,vector<P> , greater<P>>minHeap;
priority_queue<P>maxHeap;
while(j<n){
   
            maxHeap.push({nums[j], j}); //Log(n)
 minHeap.push({nums[j], j}); //Log(n)
            while(abs(maxHeap.top().first - minHeap.top().first) > 2) {
                i++;

                while(!maxHeap.empty() && maxHeap.top().second < i) {
                    maxHeap.pop();
                }

                while(!minHeap.empty() && minHeap.top().second < i) {
                    minHeap.pop();
                }
            }

            count += j-i+1;
            j++;
}
return count;

    }
};


