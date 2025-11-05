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
 
//    int maxDepth(TreeNode* root) {
   
//         if(!root) return 0;
//         int lst=maxDepth(root->left);
//         int rst=maxDepth(root->right);
//         return 1+max(lst,rst);
//     }
//     bool isBalanced(TreeNode* root) {
//     if(!root) return true;
// int leftH=maxDepth(root->left);
// int rightH=maxDepth(root->right);
// if(abs(leftH-rightH)>1) return false;
 
//  bool leftCheck= isBalanced(root->left);
//  bool rightCheck= isBalanced(root->right);
//  if(!leftCheck || !rightCheck) return false;
//  return true;
//     }

//  time : o(n)
//  space: o(recursion depth) logn for balanced tree, n for skewed tree
   int dfsHeight(TreeNode* root) {
   
        if(!root) return 0;
        int lst=dfsHeight(root->left);
        int rst=dfsHeight(root->right);
        if(lst==-1 || rst==-1) return -1;
        if(abs(lst-rst)>1) return -1;
        return 1+max(lst,rst);
    }
    bool isBalanced(TreeNode* root) {
    return dfsHeight(root)!=-1;
    }
};