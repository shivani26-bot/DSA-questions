class Solution {
public:
// if radius of a bomb1 is >= distance between 2 bombs ie bomb1 and bomb 2
// distance between 2 bombs= sqrt((x1-x2)^2 +(y1-y2)^2 )
// then only bomb 1 will cause bomb 2 to explode
// r of a bomb >=d between bombs
// d=sqrt((x1-x2)^2 +(y1-y2)^2)
// directed graph
// if bomb1 explodes bomb2 it's not necessary that bomb2 will explode bomb1 also
// it depends on the range of bomb2
//               0      1        2       3       4
//   bombs = [[1,2,3],[2,3,1],[3,4,2],[4,5,3],[5,6,4]]
typedef long long ll;
// void dfs(int node, unordered_set<int>&visited,vector<vector<int>>&adjList )
//     {
//          visited.insert(node);
//          for(auto it: adjList [node]){
//             if(visited.find(it)==visited.end()){
//                 dfs(it,visited,adjList);
//             }
//          }
//     }
int bfs(int node,vector<vector<int>>&adjList )
    {
         queue<int>q;
         q.push(node);
         unordered_set<int>visited;
         visited.insert(node);
         while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(auto it: adjList[temp]){
                if(visited.find(it)==visited.end()){
                    visited.insert(it);
                    q.push(it);
                }
            }
         }
         return visited.size();
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
vector<vector<int>>adjList(n);
        // make adjacency list 
        // check krna hai i ke fatne se jth bomb fatega ya nahi 
        // o(n^2)
        for(int b1=0;b1<n;b1++){
            for(int b2=0;b2<n;b2++){
                if(b1==b2) continue;
                ll b1_x1= bombs[b1][0];
                ll b1_y1=  bombs[b1][1];
                ll b1_r1=  bombs[b1][2];
                ll b2_x2=  bombs[b2][0];
                ll b2_y2=  bombs[b2][1];
                ll b2_r2=  bombs[b2][2];
                ll u=(b2_x2-b1_x1)*(b2_x2-b1_x1);
                ll v=(b2_y2-b1_y1)*(b2_y2-b1_y1);
                // ll distance_between_b1_b2= sqrt(u+v);
                // sqrt() returns a floating-point number, but you're storing it in an ll, which can cause precision issues.
                 ll distance_between_b1_b2= u+v;
                if(ll(b1_r1*b1_r1)>=distance_between_b1_b2)
                  adjList[b1].push_back(b2);
            }
        }
        int result=0;
        // unordered_set<int>visited;
        // for(int i=0;i<n;i++){
        //     dfs(i,visited,adjList);
        //     int count=visited.size();
        //     result=max(result,count);
        //     visited.clear();
        // }
        // return result;

// For each bomb b1
// You check all other bombs b2
// In the worst case, b1 can reach every other bomb
// So:
// Maximum outgoing edges from one node = n − 1
// Total edges in worst case
// E ≤ n × (n − 1)
// E ≤ n² − n
// Big-O ignores lower-order terms:
// E = O(n²)
// Worst-case graph:
// 0 → 1,2,3,...,n-1
// 1 → 0,2,3,...,n-1
// 2 → 0,1,3,...,n-1
// ...
// That’s a dense directed graph.

// BFS from one node
// Visits at most n nodes
// Traverses at most E edges
//        n × (n + E)
// substitue n^2 in place of E
// total time complexity n^3
// space: o(n^2)
        for(int i=0;i<n;i++){
            int count= bfs(i,adjList);
            result=max(result,count); 
        }
        return result;
    }
};