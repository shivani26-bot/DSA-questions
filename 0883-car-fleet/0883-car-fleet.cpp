class Solution {
public:

//[(pos,speed)]=[(3,3),(5,2),(7,1)] target=10
// sort based on position 
// if one car reaches the destination in less or equal time than a car ahead of it
// it means they must have meet some where in between
// to find the time taken
// (target-curr_distance)/curr_time
// (10-7)/1=3
// (10-5)/2=2.5
// the 2nd car time is less than the 3rd car time it means they will collide
// in between and the new time will be updated for the 2nd car as the minimum speed
// out of the two cars , both cars will meet at distance 9 from there they will travel with the speed 1

// If the car S (Second) behind the lead car F (First) would arrive earlier, then S forms a fleet with the lead car F. Otherwise, fleet F is final as no car can catch up to it - cars behind S would form fleets with S, never F.

// A car is a (position, speed) which implies some arrival time (target - position) / speed. Sort the cars by position.

// If a car takes less time to reach the target than the car ahead of it, it will catch up and form a car fleet with the car in front. Conversely, if a car takes more time to reach the target than the car ahead, it won't catch up before the destination and will therefore form a new car fleet separate from the one ahead.


// To solve this problem, it's essential to keep track of each car fleet's arrival time and compare it with the fleet immediately ahead.

// While data structures like hash maps could store information, a stack is particularly suitable here because it allows efficient access to the most recent fleet's arrival time for comparison.

// By using a stack, we can calculate each car's time to reach the destination and, as we iterate through the cars, determine whether the current car will catch up to the fleet ahead or form a new fleet.

// move from right to left 


    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n= position.size();
    vector<pair<int,int>>cars;
    for(int i=0;i<n;i++){
        cars.push_back({position[i],speed[i]});
    }
    sort(cars.begin(),cars.end());
stack<double>st;
        for(int i=n-1;i>=0;i--){
int pos=cars[i].first;
int spd=cars[i].second;
double timeTaken= (double)(target-pos)/spd;
if(st.empty()||timeTaken>st.top()){
    st.push(timeTaken);
}
//if time for current car is less than the car ahead of it , it means, skip that car as it will form the fleet with the ahead car 
        }
        return st.size();
    }
};