class Solution {
public:
typedef pair<int,int> P;
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        // sort based on arrival time
// assign chair to each friend, and for that 
// chair assign time at which that chair will be free ie the departure
// time of friend
// arr=[[4,6][2,3][1,4]]  targetfriend=2
// [[1,4][2,3][4,6]]

// take a vector where store the end time, for each chair
// chair0 chair1 chair2 chair3....
// 4
// chair 0 will be assigned [1,4] and chair0 stores 4 the departure time
// for [2,3] , traverse the whole vectore and see whether that chair will be free
// when a new person arrives or not
// chair0 chair1 chair2 chair3....
// 4          3
// for [4,6], chair0
// chair0 chair1 chair2 chair3....
// 6         3
// arrival time of every friend is unique, based on arrival time we can determine the target friend in the sorted array
// for targetfriend=2 arrival time is 1, corresponding departure time is 6
// int n=times.size();
// vector<int>endTimes(n,-1);// indexes represent the chair number and value indicates time at which the chair will be free
// int targetFriendArrivalTime= times[targetFriend][0];// because arrival time is unique
// // We need to sort the times based on arrival time but we don't want to
// // loose the friend number after sorting. So, store the arrival time
// // of targetFriend because it's given in the question that 
// // Each arrival time is distinct.
// sort(begin(times),end(times)); //nlogn

// for(int i=0;i<n;i++){ //n^2
//     int arrival=times[i][0];
//     int departure= times[i][1];
//     for(int j=0;j<n;j++){
//          if(endTimes[j]<=arrival){
//             endTimes[j]=departure;
//             if(arrival==targetFriendArrivalTime) return j;
//             break;
//          }


//     }
// }
// return -1;

// datastructure which can tell efficiently which chair will be available next
    // we can use miheap (departuretime, chairnumber)
    //  pop all the elements whose departuretime is less than arrival time of current friend
    //  and answer will be the minimum of all the chair number
    //  for that also we can take a minheap to store freechairs

    // time o(nlogn)
    // heap operations take logarithmic time 
    int n=times.size();
priority_queue<P,vector<P>,greater<P>>occupiedChairs;
priority_queue<int,vector<int>,greater<int>>freeChairs;
int targetFriendArrival= times[targetFriend][0];
int chairNo=0;
sort(times.begin(),times.end());

for(int i=0;i<n;i++){
    int arrival=times[i][0];
    int departure=times[i][1];
while(!occupiedChairs.empty() && occupiedChairs.top().first<=arrival){
    freeChairs.push(occupiedChairs.top().second);
    occupiedChairs.pop();
}
if(freeChairs.empty()){
occupiedChairs.push({departure,chairNo});
if(arrival==targetFriendArrival) return chairNo;

chairNo++;
}
else{
    int leastChairAvailable=freeChairs.top();
    freeChairs.pop();
    if(arrival==targetFriendArrival) return leastChairAvailable;
    occupiedChairs.push({departure,leastChairAvailable});
}
}
return -1;
    }
};