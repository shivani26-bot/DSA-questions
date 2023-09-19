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
bool rootToLeafSum(TreeNode* root, int sum, int targetSum){
  if(!root) return false;

  sum+=root->val;
if(!root->left && !root->right && sum==targetSum){
    return true;
}
 bool lst= rootToLeafSum(root->left,sum,targetSum);
 bool rst= rootToLeafSum(root->right,sum,targetSum);

 return lst||rst;
}
    bool hasPathSum(TreeNode* root, int targetSum) {
         if (!root)
        return false;
    
        int sum=0;
      return  rootToLeafSum(root,sum,targetSum);
    }
};