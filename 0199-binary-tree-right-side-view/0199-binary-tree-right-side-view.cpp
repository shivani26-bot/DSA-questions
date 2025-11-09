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

//  class Solution {
// public:
// void rightView(TreeNode* root, int level, int &maxLevel , vector<int>&ans){
//     if(!root) return ;
//     if(level>maxLevel){
//         maxLevel=level;
//         ans.push_back(root->val);
//     }
//     rightView(root->right,level+1,maxLevel,ans);
//     rightView(root->left,level+1,maxLevel,ans);
// }
//     vector<int> rightSideView(TreeNode* root) {
        
//         int maxLevel=-1;
//    int level=0;
//    vector<int>ans;
//    rightView(root,level,maxLevel,ans);
//    return ans;
//     }
// };
class Solution {
public:
//     vector<int> rightSideView(TreeNode* root) {
//         if(!root) return {};
//         queue<TreeNode*>q;
//         q.push(root);
//         vector<int>ans;

//         while(!q.empty()){
//              int size= q.size();
//             TreeNode* node=NULL;
//              while(size--){
//                  node=q.front();
// q.pop();
//  if(node->left) {
//                     q.push(node->left);
//                 }
               
//                  if(node->right) {
//                     q.push(node->right);              
//                 }
                
//              }
//              ans.push_back(node->val);
//         }
//         return ans;
//     }

// dfs preorder traversal
// ans size must be equal to number of level
void dfs(TreeNode* root, int level,vector<int>&ans){
if(!root) return;

    if(ans.size()==level){
        ans.push_back(root->val);
    }
    dfs(root->right,level+1,ans);
    dfs(root->left,level+1,ans);
}
 vector<int> rightSideView(TreeNode* root) {
     vector<int>ans;
     dfs(root,0,ans);
     return ans;
    }
};