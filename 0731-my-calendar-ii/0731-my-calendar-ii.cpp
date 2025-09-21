class MyCalendarTwo {
public:
vector<pair<int,int>>bookings;
vector<pair<int,int>>overlappings;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
          for(auto it:overlappings){
            int overlapStart=it.first;
            int overlapEnd=it.second;
           
            if(overlapStart<end && overlapEnd>start) {
               return false;
            }
        }

        for(auto num:bookings){
            int existingStart=num.first;
            int existingEnd=num.second;
           
            if(existingStart<end && existingEnd>start) {
               overlappings.push_back({max(existingStart,start),min(existingEnd,end)});
            }
        }
 cout<<endl;
        bookings.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */