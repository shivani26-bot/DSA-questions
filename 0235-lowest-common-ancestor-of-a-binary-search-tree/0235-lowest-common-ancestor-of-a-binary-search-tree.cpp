/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root->val ==p->val || root->val == q->val) return root;
        int minimum= min(p->val, q->val);
        int maximum= max(p->val, q->val);
        if(root->val > minimum && root->val <maximum) return root;
        if(root->val < minimum && root->val < maximum){
            return lowestCommonAncestor(root->right,p,q);
        }
        else{
            return lowestCommonAncestor(root->left,p,q);
        }
    }
};