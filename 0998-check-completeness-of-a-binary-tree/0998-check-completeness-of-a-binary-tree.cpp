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

// bool bfs(TreeNode* root){
//     queue<TreeNode*>q;
//     q.push(root);
//       bool foundNull=false;
//     while(!q.empty()){
//       TreeNode* node= q.front();
//       q.pop();

//       if(!node) {
//         foundNull=true; //if node is null mark it true
//       }
//       else{ //if node is present then check whether have seen null in past or not if yes then return false other wise push the left and right child 
//         if(foundNull) return false;
//         q.push(node->left);
//         q.push(node->right);// if there is null node it pushes 0, if there is node it pushes the address of the node
//         // cout<<node->left<<" "<<node->right;
//       }
        
//     }
//     return true;
// }

//     bool isCompleteTree(TreeNode* root) {

// //  if at last level we find null then after that null there should be no elements after it

// // if any node has seen null in the past it means it's not a complete binary tree

// return bfs(root);


//     }
// time : o(n)
// space: o(recursion depth, h)
int countNodes(TreeNode* root){
    if(!root) return false;
    return 1+countNodes(root->left)+countNodes(root->right);
}
bool dfs(TreeNode* root, int i, int totalNodes){

    if(!root) return true;
    if(i>totalNodes) return false;
    return dfs(root->left, 2*i,totalNodes) && dfs(root->right,2*i+1,totalNodes);
}
    bool isCompleteTree(TreeNode* root) {
//  represent tree in array, if index  > number of nodes in a tree then it will not be a complete binary tree, if it's a complete binary tree we will never get the gap in between nodes, count total number of nodes, then run dfs for root->left and root->right, store elements in root->left to 2*i index of array and root->right to 2*i+1 index

int totalNodes= countNodes(root);
int i=1;
return dfs(root,i,totalNodes);


    }
};