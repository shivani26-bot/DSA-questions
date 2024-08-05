class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        // use dijkstra algorithm
        // maintain two distance array
        // first will keep track of minimum distance to reach any node
        // second will keep track of second minimum distance to reach any node
        // we should visit any node only twice not more than that to find the minimum and
        // second minimum to reach that node
        // at start all the nodes are green after every change interval the colour of all the nodes
        // changes together either to green to red or red to green
        // in order to find the how many interval has been passed
        // timepassed/change, extract the integer part of it to find the interval already passed
        // if odd number of interval is passed it means that all the nodes are at red signal currently and we 
        // will have to wait till the next interval(green) so that we can move
        // to find the next interval, ((integer part of timepassed/change) +1 )* change
        // if even number of interval is passed then we are already at green signal are we are free to move
        // store time,node in priority queue
        unordered_map<int,vector<int>>adj;
        for(auto it: edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>minDistance(n+1,1e9);
        vector<int>secondMinDistance(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,1});
        minDistance[1]=0;
        while(!pq.empty()){
            int timePassed=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(node==n && secondMinDistance[n]!=1e9) return secondMinDistance[n];
            int passedInterval= timePassed/change;
            if(passedInterval%2==1) {
                // we are currently at red interval, find out the next time when we will have green signal so that we can move freely
               timePassed=(passedInterval+1)*change;
            }
            for(auto nbr:adj[node]){
                if(minDistance[nbr]>timePassed+time){
                    secondMinDistance[nbr]=minDistance[nbr];
                    minDistance[nbr]=timePassed+time;
                    pq.push({timePassed+time,nbr});
                }
                // don't place the same value in secondMinDistance if minDistance[nbr]==timePassed+time
                else if(secondMinDistance[nbr]>timePassed+time && minDistance[nbr]!=timePassed+time){
                    secondMinDistance[nbr]=timePassed+time;
                    pq.push({timePassed+time,nbr});
                }
            }
        }
        return -1;
    }

};