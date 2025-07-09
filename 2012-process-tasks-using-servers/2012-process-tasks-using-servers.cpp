class Solution {
public:
// [10,63,95,16,85,57,83,95,6,29,71]
// [70,31,83,15,32,67,98,65,56,48,38,90,5]
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        vector<int>result;
       // Available servers: {weight, index}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> serversIdx;
        
        // Busy servers: {freeTime, weight, index}
        priority_queue<array<int,3>, vector<array<int,3>>, greater<>> tasksQueue;

        int n=servers.size();
        for(int i=0;i<n;i++){
            serversIdx.push({servers[i],i});
        }

        int currTime=0;
        int m=tasks.size();
        // ✅ Fix: If all servers are busy, currTime should jump to the earliest free time, not increment step-by-step.


        for(int j=0;j<m;j++){
currTime=max(currTime,j);    
//free up the servers that are done with tasks
while(!tasksQueue.empty() && tasksQueue.top()[0]<=currTime){
    auto [freeTime,weight,idx] =tasksQueue.top();
    tasksQueue.pop();
    serversIdx.push({weight,idx});
}
//when no servers are free, fast forward time to next available server
if(serversIdx.empty()){
currTime=tasksQueue.top()[0];
while(!tasksQueue.empty() && tasksQueue.top()[0]<=currTime){//it means currTime is t and all the task whose time in the tasksQueue< t will means those tasks are completed and we should free up the server performing those tasks
    auto [freeTime,weight,idx] =tasksQueue.top();
    tasksQueue.pop();
    serversIdx.push({weight,idx});
}
}


auto [weight, idx]=serversIdx.top();//pick a new server to perform the current task if other servers are busy
serversIdx.pop();

int freeTime=currTime+tasks[j];
tasksQueue.push({freeTime,weight,idx});
result.push_back(idx);

        }
        return result;
    }
};