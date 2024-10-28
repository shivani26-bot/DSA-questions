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
// root1=[1] root2=[2]
// int worst case o(4*n) we traverse the tree 4 time
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return true;
         if(!root1 || !root2) return false;
         if(root1->val==root2->val){
    bool without_flip= flipEquiv(root1->left,root2->left) && 
    flipEquiv(root1->right,root2->right);
        bool with_flip= flipEquiv(root1->left,root2->right) && 
    flipEquiv(root1->right,root2->left);
    return without_flip || with_flip;
         }
      return false;
     
    }
};

//mirror binary tree
// invert binary tree
// check if two trees are identical
// check if binary tree is foldable 