/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
// int numberOfGoodLeaves;
// vector<int>dfs(TreeNode* node, int &dis){
// if(!node) return {};
// if(!node->left && !node->right) return {1};

//     vector<int>leftv=dfs(node->left,dis);
//      vector<int>rightv=dfs(node->right,dis);

//      for(auto lv: leftv){
//         for(auto rv: rightv){
//             if(lv+rv<=dis) numberOfGoodLeaves++;
//         }
//      }
//      vector<int>parentv;
//      for(auto lv: leftv){
//         if(lv+1<=dis) parentv.push_back(lv+1);
//      }
//      for(auto rv: rightv){
//         if(rv+1<=dis) parentv.push_back(rv+1);
//      }
//      return parentv;
// }


    // int countPairs(TreeNode* root, int distance) {
    //     numberOfGoodLeaves=0;
    //   dfs(root,distance);
    //   return numberOfGoodLeaves;
    // }

void makeGraph(TreeNode* root,
unordered_map<TreeNode*,vector<TreeNode*>>&adj,
unordered_set<TreeNode*>&leafNodes,TreeNode* prev ){
    if(!root) return;

    if(!root->left && !root->right){
        leafNodes.insert(root);
    }
    if(prev!=NULL){
        adj[root].push_back(prev);
        adj[prev].push_back(root);
    }
    makeGraph(root->left, adj, leafNodes, root);
    makeGraph(root->right, adj, leafNodes, root);
}
 int countPairs(TreeNode* root, int distance) {
   
    // convert the tree into undirected graph, while doing so store the leaf nodes
    // find shortest distane between all the leaf nodes, while counting the pairs 
    // we accidentally count the duplicate pairs as well
    // hence divide the final count of the answer by 2 to eliminate the duplicates
    // to find the shortest distance we use bfs 
 

//  [1,2,3,4,5,6,7]
// start bfs from each leaf nodes one by one
// leaf nodes={4,5,6,7}
// level0 =4, its neighbour 2 at level 1, level 1 <=distance
// for node 2 , its neighbour 1,5 at level 2, level2 <=distance
// at level 2 we have 1,5 and 5 is leaf node which is at distance =2 from 
// node 4 hence we can add count of this pair
// for node1, its neighbour is 3 at level 3, 3 is pushed into queue
// and for node 5 there is no neighbour, 
// for node 3 , it's neighbour is  6,7 at level 4, distance=4, hence we will not 
// consider this level as its distance is greater than the required distance ie 3

// similarly start bfs from node =5,6,7
// don't go on level whose distance is > than required distance
// traverse bfs till level distance <= required distance


// while making a graph, the edge already directed from u to v, we just
// have to make an edge directed from v to u, to do so we must know the previous
// node of the current node so that we can connect the current node to previous node
// in reverse fashion
// initially prevvious node is NULL 

unordered_map<TreeNode*,vector<TreeNode*>>adj;
unordered_set<TreeNode*>leafNodes;
makeGraph(root,adj,leafNodes,NULL);
int count=0;
for(auto leaf: leafNodes){
    // bfs from each leaf nodes
    queue<TreeNode*>q;
    unordered_set<TreeNode*>visitedNode;
    q.push(leaf);
    visitedNode.insert(leaf);

    for(int level=0;level<=distance;level++){
        int size=q.size();
        while(size--){
            TreeNode* currNode=q.front();
            q.pop();
            // if currnode is not a leaf node for which we are running bfs
            // but it's a leaf node 
            if(currNode!=leaf && leafNodes.count(currNode)){
                count++;
            }
            for(auto it: adj[currNode]){
                if(visitedNode.count(it)==0){
                    q.push(it);
                    visitedNode.insert(it);
                }
            }
        }
    }
}
return count/2;
 }

};