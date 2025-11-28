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
//     TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
//         // root node will not be a child of any other node
//         // make a hashmap to check that for specific value we have a treeNode structure or not 
//         // how to find the root node?
//         // maitain a hashmap and keep track of child and parent while traversing, the root node will not have
//         // child in the end 
// //         unordered_map<int,TreeNode*>nodeToTree;
// //         unordered_map<int,bool>hasParent;
// //         TreeNode* parentNode=nullptr,*childNode=nullptr;
        
// //         for(auto it: descriptions){
// //             // it[0]->parent
// //             // it[1]->child
// //             // it[2]->isLeftchild or not 
// //             if(nodeToTree.find(it[0])==nodeToTree.end())
// //                  parentNode= new TreeNode(it[0]);
// //             else parentNode=nodeToTree[it[0]];
// // if(nodeToTree.find(it[1])==nodeToTree.end())
// //                  childNode= new TreeNode(it[1]);
// //             else childNode=nodeToTree[it[1]];

// //             if(it[2]==1) parentNode->left=childNode;
// //             else parentNode->right=childNode;
// //             hasParent[it[1]]=true;
// //             nodeToTree[it[0]]=parentNode;
// //             nodeToTree[it[1]]=childNode;
// //         }
// //         TreeNode* rootNode=nullptr;
// //         for(auto it:nodeToTree){
// //             if(!hasParent[it.first]) rootNode=it.second;
// //         }
// //         return rootNode;

// unordered_map<int,TreeNode*>mp;
// unordered_set<int>childNodes;

// for(auto it: descriptions){
//     int parent=it[0];
//     int child=it[1];
//     bool isLeft=it[2];
//     if(mp.find(parent)==mp.end()){
//         mp[parent]=new TreeNode(parent);
//     }
//     if(mp.find(child)==mp.end()){
//         mp[child]=new TreeNode(child);
//     }
//     if(isLeft==1){
//         mp[parent]->left=mp[child];
//     }
//     else{
//         mp[parent]->right=mp[child];
//     }
//     childNodes.insert(child);
// }

// for(auto it: descriptions){
//     //search for parent which is not present in the child set
//     if(childNodes.find(it[0])==childNodes.end()){
//         return mp[it[0]];
//     }
// }
// return NULL ;//Will never reach here
//     }


    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
unordered_map<int,TreeNode*>mp;//integer to node
unordered_set<int>childNodes;
for(auto it: descriptions){
    int parent=it[0];
    int child=it[1];
    int isLeft=it[2];
    if(mp.find(parent)==mp.end()){
        mp[parent]=new TreeNode(parent);
    }
 if(mp.find(child)==mp.end()){
        mp[child]=new TreeNode(child);
    }
    if(isLeft==1){
        mp[parent]->left=mp[child];
    }
    else{
        mp[parent]->right=mp[child];
    }
    childNodes.insert(child);
}
for(auto it: descriptions){
    // check whether parent is present in child nodes set or not
    // the element which is not present in child nodes is the answer, the parent root node is never a child of any other node 
    int parent=it[0];
    if(childNodes.count(parent)==0) return mp[parent];
}
return NULL;
    }
};


// all parents and children share the same TreeNode* pointer stored in the map.
// So when you modify the node for 80, the change is visible inside the 50 subtree as well — because both refer to the same object in memory.
// unordered_map<int, TreeNode*> mp;
// This means:
// Key → node value (like 50, 20, 80...)
// Value → pointer to ONE TreeNode object in memory

// So:
// 1. When this line runs:
// mp[80] = new TreeNode(80);
// It stores one pointer to a node with value 80.

// 2. Later when you attach this node:
// mp[50]->right = mp[80];
// 50's right child now points to the same exact object as stored at mp[80].

// 3. If later you modify the node for 80:
// mp[80]->left = mp[19];
// Then 50->right->left also changes because:

// 50->right == mp[80]
// They are not separate copies, they are the same pointer.