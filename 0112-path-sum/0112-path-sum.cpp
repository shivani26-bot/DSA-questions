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
    if (!root)
        return false;
    
    sum += root->val;

    // Check if it's a leaf node and if the sum matches the targetSum
    if (!root->left && !root->right && sum == targetSum)
        return true;

    // Recursively check the left and right subtrees
    bool leftResult = rootToLeafSum(root->left, sum, targetSum);
    bool rightResult = rootToLeafSum(root->right, sum, targetSum);

    // Return true if either the left or right subtree has a valid path
    return leftResult || rightResult;
}
    bool hasPathSum(TreeNode* root, int targetSum) {
         if (!root)
        return false;
    
        int sum=0;
      return  rootToLeafSum(root,sum,targetSum);
    }
};