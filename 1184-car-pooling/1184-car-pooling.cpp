class Solution {
public:
// [[2,1,5],[3,5,7]] 3
// [[7,5,6],[6,7,8],[10,1,6]] 16
// [[3,2,7],[3,7,9],[8,3,9]] 11
    bool carPooling(vector<vector<int>>& trips, int capacity) {
//          passing by const reference, because:
// You’re only reading the vectors (a[1], a[2]).
// Passing by non-const reference means it expects modifiable input, which isn’t necessary and could cause issues with STL algorithms like sort if you try to use them with const vectors.


        auto comp= [](const vector<int>&a, const vector<int>&b){
            return a[1]<b[1] || (a[1]==b[1] && a[2]<b[2]);
        };
        sort(trips.begin(),trips.end(),comp);
        int n=trips.size();
int currCapacity=0;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>pq;//{destination, numPassenger}
        for(int i=0;i<n;i++){
//remove all the passengers whose destination <= current location of ith trip and subtract corresponding number of passenger from currCapacity
while(!pq.empty() && pq.top().first<= trips[i][1]){
    currCapacity-=pq.top().second;
    pq.pop();
}

//other wise add passenger to current capacity
pq.push({trips[i][2],trips[i][0]});
currCapacity+=trips[i][0];

// currCapacity>capacity false
if(currCapacity>capacity) return false;
        }
        return true;//we reached end of the array
    }
};