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
//  time o(n+m)
//  n= number of nodes in tree1
//  m=number of nodes in tree2, we are visiting all the nodes once
//  space: recursion stack o(h) and leaf vectors v1 and v2
//  For a complete or perfect binary tree with n total nodes:About half the nodes are at the last level. number_of_leaves ≈ n / 2
// Leaf storage alone → O(n) space.
// o(w1+w2)
class Solution {
public:
void dfs1(TreeNode* root,vector<int>&v1){
if(!root) return;
if(!root->left && !root->right) {
    v1.push_back(root->val);
}

    dfs1(root->left,v1);
    dfs1(root->right,v1);
}
void dfs2(TreeNode* root,vector<int>&v2){
if(!root) return;
if(!root->left && !root->right) {
    v2.push_back(root->val);
}

    dfs2(root->left,v2);
    dfs2(root->right,v2);
}
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        vector<int>v1,v2;
       dfs1(root1,v1);
            dfs2(root2,v2);
            return v1==v2;
    }
};