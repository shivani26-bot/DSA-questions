
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // apply topological sort, detect whether graph has cycle or not
        // if graph has cycle then it means it's not possible to complete all the courses return false
        // else return true
        // vector<vector<int>> adj(numCourses);//this is also correct

        vector<int>adj[numCourses];//This declares an array of vectors. The size of the array is numCourses, and each element in the array is a vector<int>.static allocation of the array,
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
//   int indegree[numCourses]={0};
vector<int>indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it: adj[i]){
              indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(topo.size()==numCourses) return true;
        return false;
    }
};