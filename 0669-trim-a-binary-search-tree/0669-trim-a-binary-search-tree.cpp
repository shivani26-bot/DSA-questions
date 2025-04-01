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

// tc: o(n)

// if root->val<low it means, return right subtree as left subtree will have all the elements lesser than low
// if root->val>high it means, return left subtree as right subtree will have all the elements greater than high;
TreeNode* solve(TreeNode* root, int low, int high){
      if(!root) return NULL;
      if(root->val<low) return solve(root->right,low,high);
      if(root->val>high) return solve(root->left, low, high);
      root->left=solve(root->left,low,high);
      root->right=solve(root->right,low,high);
      return root;
}
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root) return NULL;
        return solve(root,low,high);

    }
};