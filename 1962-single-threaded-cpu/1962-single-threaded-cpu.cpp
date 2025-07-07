class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        // sort tasks by enqueue time
    //    tasks will be performed based on smallest enqueue time, if while performing the task some other tasks come it will wait in a queue, once task is finished, if there are multiple tasks to perform then based on smallest processing time task will be performed, if processing time is same then the the task with smallest index will be performed
    // minheap {duration,index}
//     i
// [{1,2},{2,4},{3,2},{4,1}]
// [{1,2,0},{2,4,1},{3,2,2},{4,1,3}] {enqueuetime, processtime,idx}

// priority queue(min-heap,(duration time, index))
// current_time=0;
// current_time=1, look whether any task can come while performing this task also push this in pq
// pq: (2,0 )
// currenttime=1
// process time:2
// index:0
// currenttime+=processtime //3
// currenttime is 3
// hence pq: (4,1) (2,2)
// i=3, currenttime is 3, pop from top
// proesstime:2
// index:2
// currenttime+=processtime//5
// pq: (4,1)(1,3)
//  processingtime:1
//  index:3
// currenttime+=processingtime//6
// pq:(4,1)
// processtime:4
// index:1
// currenttime+=processtime//10
//nlogn

        int n=tasks.size();
        vector<array<int,3>>sortedTasks;
        //sort based on starting time of tasks
         
        for(int i=0;i<n;i++){
           int start_time=tasks[i][0];
           int processing_time=tasks[i][1];
           sortedTasks.push_back({start_time, processing_time, i});

        }
        sort(sortedTasks.begin(),sortedTasks.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int>result;
        long long curr_time=0;
        int idx=0;
    
        while(idx<n || !pq.empty()){ 
            if(pq.empty() && curr_time<sortedTasks[idx][0]){
                curr_time=sortedTasks[idx][0];
            }
            while(idx<n && sortedTasks[idx][0]<=curr_time){
                pq.push({sortedTasks[idx][1],sortedTasks[idx][2]});//logn
                idx++;
            }
            pair<int,int>curr_task=pq.top();
            pq.pop();
            curr_time+=curr_task.first;//processing time
            result.push_back(curr_task.second);
        }
        return result;
        
    }
};