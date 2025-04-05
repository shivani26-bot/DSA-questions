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
int sum=0;

void solve(TreeNode* root){
   if(!root) return;
   solve(root->right);
   sum+=root->val;
   root->val=sum;
   solve(root->left);
}
    TreeNode* convertBST(TreeNode* root) {
        // brute force: as this is a bst, we can store the elements in sorted form in array using inorder traversal, then traverse throught the nodes, find that node in the array and add all the element greater than that node element to the node of the tree 
        // o(n*n)
        solve(root);
        return root;
    }
};