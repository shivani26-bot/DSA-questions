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
// time:o(n):
// Each node is visited exactly once.
// Each recursive call processes one node and makes two recursive calls (left and right).
// Since there are N nodes in the tree, the function runs in O(N) time.
// space: recursion stack depth depends on height of tree
// If the tree is balanced, height = O(log n).
// If the tree is skewed (like a linked list), height = O(n).
// Total Space (including output) O(n)
// space excluding output o(h) : Recursion stack — proportional to the tree’s height.
// Because you store all node values in ans.
void preorder(TreeNode* root, vector<int>&ans){
  if(!root) return ;
   ans.push_back(root->val);
        preorder(root->left,ans);
       
        preorder(root->right,ans);
}
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
preorder(root,ans);
        return ans;
    }
};