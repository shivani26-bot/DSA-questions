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
//  int countPairs(TreeNode* root, int distance) {
   
//     // convert the tree into undirected graph, while doing so store the leaf nodes
//     // find shortest distance between all the leaf nodes, while counting the pairs 
//     // we accidentally count the duplicate pairs as well
//     // hence divide the final count of the answer by 2 to eliminate the duplicates
//     // to find the shortest distance we use bfs 
 

// //  [1,2,3,4,5,6,7]
// // start bfs from each leaf nodes one by one
// // leaf nodes={4,5,6,7}
// // level0 =4, its neighbour 2 at level 1, level 1 <=distance
// // for node 2 , its neighbour 1,5 at level 2, level2 <=distance
// // at level 2 we have 1,5 and 5 is leaf node which is at distance =2 from 
// // node 4 hence we can add count of this pair
// // for node1, its neighbour is 3 at level 3, 3 is pushed into queue
// // and for node 5 there is no neighbour, 
// // for node 3 , it's neighbour is  6,7 at level 4, distance=4, hence we will not 
// // consider this level as its distance is greater than the required distance ie 3

// // similarly start bfs from node =5,6,7
// // don't go on level whose distance is > than required distance
// // traverse bfs till level distance <= required distance


// // while making a graph, the edge already directed from u to v, we just
// // have to make an edge directed from v to u, to do so we must know the previous
// // node of the current node so that we can connect the current node to previous node
// // in reverse fashion
// // initially prevvious node is NULL 

// unordered_map<TreeNode*,vector<TreeNode*>>adj;
// unordered_set<TreeNode*>leafNodes;
// makeGraph(root,adj,leafNodes,NULL);
// int count=0;
// for(auto leaf: leafNodes){
//     // bfs from each leaf nodes
//     queue<TreeNode*>q;
//     unordered_set<TreeNode*>visitedNode;
//     q.push(leaf);
//     visitedNode.insert(leaf);

//     for(int level=0;level<=distance;level++){
//         int size=q.size();
//         while(size--){
//             TreeNode* currNode=q.front();
//             q.pop();
//             // if currnode is not a leaf node for which we are running bfs
//             // but it's a leaf node 
//             if(currNode!=leaf && leafNodes.count(currNode)){
//                 count++;
//             }
//             for(auto it: adj[currNode]){
//                 if(visitedNode.count(it)==0){
//                     q.push(it);
//                     visitedNode.insert(it);
//                 }
//             }
//         }
//     }
// }
// return count/2;
//  }


int numberOfGoodLeaves=0;
vector<int>solve(TreeNode* root, int distance){
if(!root) return {};
if(!root->left && !root->right) return {1}; //leaf node

  vector<int>lst=  solve(root->left,distance);
vector<int>rst= solve(root->right,distance);

for(auto l:lst){
    for(auto r:rst){
        if(l+r<=distance) numberOfGoodLeaves++;
    }
}
vector<int>parent;
for(auto l: lst){
    if(l+1<=distance) parent.push_back(l+1);
}
for(auto r: rst){
    if(r+1<=distance) parent.push_back(r+1);
}
return parent;
}
int countPairs(TreeNode* root, int distance) {
    solve(root,distance);
return numberOfGoodLeaves;
 }

};


// tree traversal, and we know how to send information from child to parent 
// yha child to parent, kya info bhejni chahiye such that parent can find distance 
// child to parent send distance , agr child bta de parent ko ki uski kya distance hai from parent
// agr jo left and right child se vector mile uska pair bnaye, aur hrr pair  ko add krke agr distance <=dist 
// aayega toh number of goodLeaves++
// parent ko hmesha ekk vector jayega jisme left aur right child ke wo sare nodes honge jinka value+1<=dist hoga

//                        {2,3,3} 1 {2,2} 

//          {1} 2 {2,2}                         {1} 3 {1}

//   4                  {1} 5 {1}             6           7

//                    8            9
// dist=3
// numberofgoodleaves=4
// (length of vector represent how many leaf nodes and element represent and what is there distance from node 1, right side of 1 has 2 leaf node at distance 2 , 2 and left side has 3 nodes at distance 2,3,3)

    // kisi node k pass vector mein kitne element hai that will represent how many leaf nodes are comming from left and right subtree 