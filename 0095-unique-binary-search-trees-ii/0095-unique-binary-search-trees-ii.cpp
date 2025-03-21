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
// vector<TreeNode*> solve(int start, int end){
//    if(start>end) return {NULL};
//    if(start==end) {
//     TreeNode* root= new TreeNode(start);
//     return {root};
//    }
// vector<TreeNode*>result;
//    for(int i=start;i<=end;i++){
//     vector<TreeNode*> leftList= solve(start,i-1);
//     vector<TreeNode*> rightList=solve(i+1,end);
// for(TreeNode* leftRoot:leftList){
//     for(TreeNode* rightRoot:rightList){
//         TreeNode* root= new TreeNode(i);
//         root->left=leftRoot;
//         root->right=rightRoot;
//         result.push_back(root);
//     }
// }
//    }
//    return result;
// }
//     vector<TreeNode*> generateTrees(int n) {
//         // return root for every tree 
//         // map will be used for memoization 
//         // similar to 894. All Possible Full Binary Trees
//         // o(n*m) 
//         // m is catalan number for each n=0,1,2,3...number of nodes
// //    if i is the root
// //    n=6
// //    s     i   e
// //    1,2,3,4,5,6
// //    for ith node as root, lhs subtree will be start, i-1 and rhs subtree will be i+1, end
// // from 1 to 6 every node will be root 

// //               4
// //    1,2,3              5,6
// //    b1,b2,b3           b5,b6
// //     4               4
// // b1     b5        b1     b6
// //     4               4
// // b2     b5        b2     b6
// //     4               4
// // b3     b5        b3     b6

// // pair the left bsts with each right bsts
//  return solve(1,n);

//     }
vector<TreeNode*> solve(int start, int end){
   if(start>end) return {NULL};
   if(start==end) {
    TreeNode* root= new TreeNode(start);
    return {root};
    }
    if(mp.find({start,end})!=mp.end())
    return mp[{start,end}];
vector<TreeNode*>result;
   for(int i=start;i<=end;i++){
    vector<TreeNode*> leftList= solve(start,i-1);
    vector<TreeNode*> rightList=solve(i+1,end);
for(TreeNode* leftRoot:leftList){
    for(TreeNode* rightRoot:rightList){
        TreeNode* root= new TreeNode(i);
        root->left=leftRoot;
        root->right=rightRoot;
        result.push_back(root);
    }
}
   }
   return mp[{start,end}]=result;
}
map<pair<int,int>,vector<TreeNode*>>mp;
    vector<TreeNode*> generateTrees(int n) {
    // memoization, we can store for every start and end what are the
    // vector of root nodes , store this in map 
    return solve(1,n);
    }
};