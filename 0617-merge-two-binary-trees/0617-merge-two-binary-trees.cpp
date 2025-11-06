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
// time: o(n) n= total number of nodes in both trees (upto to larger one)
// total number of visited nodes= total nodes in smaller + unmatched nodes in larger tree
// space:o(h)
// h-> recursin depth
// balanced tree logn , skewed tree n
TreeNode* mergedTree(TreeNode* r1, TreeNode* r2){
    if(!r1 && !r2) return NULL;
if(!r1) return r2;
if(!r2) return r1;


    TreeNode* root= new TreeNode(r1->val+r2->val);
    root->left= mergedTree(r1->left, r2->left);
    root->right=mergedTree(r1->right, r2->right);
    return root;
}
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return mergedTree(root1,root2);
    }
};