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
//     bool hasPathSum(TreeNode* root, int targetSum) {

//         if (root == NULL)
// return false;
// if (root->left == NULL && root->right == NULL && targetSum - root->val == 0)
// return true;
// return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
        
//     }
// };
//  class Solution {
// public:
// bool rootToLeafSum(TreeNode* root, int sum, int targetSum){
//   if(!root) return false;

//   sum+=root->val;
// if(!root->left && !root->right && sum==targetSum){
//     return true;
// }
//  bool lst= rootToLeafSum(root->left,sum,targetSum);
//  bool rst= rootToLeafSum(root->right,sum,targetSum);

//  return lst||rst;
// }
//     bool hasPathSum(TreeNode* root, int targetSum) {
//          if (!root)
//         return false;
    
//         int sum=0;
//       return  rootToLeafSum(root,sum,targetSum);
//     }
// };
class Solution {
public:
// time: o(n)
// each node is visited exactly once, for each node only o(1) operation sum
// space :o(h)
// h height of recursion tree (depth of binary tree)
// balanced->o(logn)
// skewed->o(n)
bool pathSum(TreeNode* root, int targetSum,int &sum){
if(!root) {
 return false;
}
    sum+=root->val;
    if(!root->left && !root->right){
       
        if(sum==targetSum) return true;
       
    }
    bool lst= pathSum(root->left, targetSum, sum);
    bool rst= pathSum(root->right, targetSum, sum);

    sum-=root->val;
    return lst||rst;
}
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        int sum=0;
        return pathSum(root, targetSum,sum);
    }
};