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
int findMaxDepth(TreeNode* root){

 if(!root) return 0;

        int lst= findMaxDepth(root->left);
        int rst= findMaxDepth(root->right);
        return 1+max(lst,rst);
    

}
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        int leftDepth= findMaxDepth(root->left);
        int rightDepth= findMaxDepth(root->right);
        return max({leftDepth+rightDepth,diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)});
    }
};