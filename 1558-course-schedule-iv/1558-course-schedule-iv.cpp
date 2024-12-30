class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool>ans;
        vector<vector<bool>>table(numCourses,vector<bool>(numCourses,false));
        vector<int>indegree(numCourses,0);
    //    vector<int>adj[numCourses];
       vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indegree[prerequisites[i][1]]++;
        }
queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int currNode=q.front();
            q.pop();
            for(auto it: adj[currNode]){
                table[currNode][it]=true;
                for(int i=0;i<numCourses;i++){
                    if(table[i][currNode]==true) table[i][it]=true;
                }
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
          
        }
          for(int i=0;i<queries.size();i++){
                ans.push_back(table[queries[i][0]][queries[i][1]]);
            }
return ans;
    }
};