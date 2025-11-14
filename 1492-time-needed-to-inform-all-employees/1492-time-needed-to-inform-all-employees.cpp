class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>>adjList;
     
        for(int i=0;i<manager.size();i++){
            int u=manager[i];
            // int time=informTime[u];// time required by the manager to inform his subordinated
            int v=i;

            if(u==-1){ continue;} //it's head node=i, or head of the company 
            adjList[u].push_back(v); //u is manager, v are employees directly under him
        }
         for (const auto& [node, neighbors] : adjList) {
        cout << "Node " << node << " -> ";
        for (int neighbor : neighbors) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
// maximum time to reach the last level will be the answer
queue<pair<int,int>>q;  //stores the node, start from headNode
int maxTime=0;
q.push({headID,0});//node, time to reach that node
      while(!q.empty()){
    
        int curr_employee=q.front().first;
        int curr_time=q.front().second;///time taken by node to spread the news to his subordinates
    
maxTime=max(maxTime,curr_time);
       q.pop();
   

if(adjList.find(curr_employee)!=adjList.end()){
for(auto it: adjList[curr_employee]){
    cout<<it<<" "; 
    int adjTime=curr_time+informTime[curr_employee];
q.push({it,adjTime});
}
}
cout<<endl;
        }

return maxTime;
    }
};