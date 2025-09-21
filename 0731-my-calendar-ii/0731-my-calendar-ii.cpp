class MyCalendarTwo {
public:
vector<pair<int,int>>bookings;
vector<pair<int,int>>overlappings;
// overlappings will store the overlapping between two intervals, if we iterate over this array
// it means two intervals has already overlapped, if current also lie in overalpping range then it means 3 intervals overlapped 
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
    //now before going to booking check in overlapping array whether there is overlapping intervals
    // between 3 intervals, because overlapping array already contains the overalpping between 2 intervals 
    for(auto it:overlappings){
        int overlapStart=it.first;
        int overlapEnd=it.second;

        if(overlapStart<end && overlapEnd>start) return false;
    }


    for(auto num:bookings){
// when there are elements in booking array try to find the overlapping with current interval and store in overlappings array
int existingStart=num.first;
int existingEnd=num.second;
if(existingStart<end && existingEnd>start){
    overlappings.push_back({max(existingStart,start),min(existingEnd,end)});
}
    }

//for the first booking push directly inside the booking and for futher bookings check the above conditions
    bookings.push_back({start,end});
    return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */