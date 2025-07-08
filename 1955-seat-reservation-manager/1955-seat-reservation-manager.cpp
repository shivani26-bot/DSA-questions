class SeatManager {
public:
        priority_queue<int,vector<int>,greater<int>>pq;

    SeatManager(int n) {//seat manager with n seats
        for(int i=1;i<=n;i++){
            pq.push(i);
        }
    }
    
    int reserve() {
        int reservedSeat=pq.top();
        pq.pop();//logn
        return reservedSeat;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);//logn
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */