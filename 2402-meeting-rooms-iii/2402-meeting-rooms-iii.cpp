class Solution {
public:
#define ll long long int


    int mostBooked(int n, vector<vector<int>>& meetings) {
        // room becomes unused, meetings that have an earlier original start time should be given the room.
        // the above point means that we should sort the meeting on basis of start time in ascending order 
        // keep track of rooms that are empty or or free at the moment.
        // unused room with the lowest number.
        // the above point means that we have to use data structure which maintains the free room with lowest number , hence use minheap
        // as soon as room is occupied it goes out of free room 
    //     also keep track that any of the room is available out of the occupied rooms, data structure minHeap containing {endtime, roomid}
    //     if we are at current room, we also check that any of the occupied rooms get free up, then grab the 
    //     meeting which has the smallest end time
    //     if smallest end time <= current end time then we can free up the rooms
    // if all the rooms are occupied,grab the room id with smallest endtime because current meeting will happen in that room id once the ocuppied room id with smallest end time  finishes the meeting,  here duration of current meeting will remain same, but its start and end time will change.
  sort(meetings.begin(),meetings.end());
   priority_queue<int,vector<int>,greater<int>>freeRooms; // track of room id
   auto static compare = [](const pair<ll,int>&a, const pair<ll,int>&b){
              if(a.first==b.first){
                // sort in ascending order bases upon room id
                // remember , in order to sort in ascending order in priority queue, its opposite of the standard sorting
            //  standard sorting    return a.second<b.second ;
                return a.second > b.second;
              }
              else{
                return a.first >b.first;
              }
};
priority_queue<pair<ll,int>,vector<pair<ll,int>>,decltype(compare)>occupiedRooms;// track of endtime and room id

// if any existing occupied room can be freed up before starting in current meeting 
// if free rooms are available choose the smallest id free room
// if free room not available choose the smallest end time out of occupied rooms ,book that room for upcoming meeting and update the time range of the upcoming meeting.          
//  keep track of frequency of how many meetings held in each room id 
    map<int,int>booked;
  for(int i=0;i<n;i++) freeRooms.push(i);
  for(auto v:meetings){
   ll start=v[0],end=v[1];
  while(!occupiedRooms.empty() && occupiedRooms.top().first<=start){
    freeRooms.push(occupiedRooms.top().second);
    occupiedRooms.pop();
  }
   if(!freeRooms.empty()){
    booked[freeRooms.top()]++;
    occupiedRooms.push({end,freeRooms.top()});
    freeRooms.pop();
   }
   else{
    booked[occupiedRooms.top().second]++;
    auto p=occupiedRooms.top();
    occupiedRooms.pop();
    occupiedRooms.push({p.first+end-start,p.second});
   }
  }
int maxRooms=0, meetingRoom=-1;
  for(auto it: booked){
if(it.second>maxRooms){
    maxRooms=it.second;
    meetingRoom=it.first;
}
  }
  return meetingRoom;
    }
};